#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct	s_data
{
	int		hex;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		dot;
	int		precision;
	char	*length;
	char	specifier;
}				t_data;

int				ft_printf(char *format, ...);

void			handle_mod(char **format, va_list args, int *count);
t_data			*init_data();
// static void			init_types(char **modifier);
char			**init_length_specifers(void);

// int				check_length(char **ref, char *str);
int				check_specifier(char c);
void			check_info(t_data *info);

void			parse_flags(t_data *info, char **format);
void			parse_width(t_data *info, char **format);
void			parse_precision(t_data *info, char **format);
void			parse_length(t_data *info, char **format);
void			parse_specifier(t_data *info, char **format);

char			*get_hex(t_data *info, long num, int *len);
void			print_format(t_data *info, va_list args, int *count);

#endif
