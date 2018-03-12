#include "ft_printf.h"

// conversions: sSpdDioOuUxXcC
// %%
// flags: #0-+ and space
// minimum field-width: if str < min, pads with spaces, used to align tables
// precision
// length hh, h, l, ll, j, z

t_data	*init_data()
{
	t_data *info;

	info = malloc(sizeof(t_data));
	info->hex = 0;
	info->zero = 0;
	info->minus = 0;
	info->plus = 0;
	info->space = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = 0;
	info->length = "";
	info->specifier = '\0';
	return (info);
}

int		check_flags(t_data *info, char **format)
{
	if (**format == '#')
		info->hex = 1;
	else if (**format == '-')
		info->minus = 1;
	else if (**format == '+')
		info->plus = 1;
	else if (**format == ' ')
		info->space = 1;
	else if (**format == '0')
		info->zero = 1;
	else
		return (0);
	return (1);
}

void	parse_flags(t_data *info, char **format)
{
	while (check_flags(info, format))
		(*format)++;
}

void	parse_width(t_data *info, char **format)
{
	if (ft_isdigit(**format))
		info->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void	parse_precision(t_data *info, char **format)
{
	char	*ptr;

	ptr = *format;
	if (*ptr != '.')
		return ;
	info->dot = 1;
	ptr++;
	*format = ptr;
	if (!ft_isdigit(*ptr))
		return ;
	info->precision = ft_atoi(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	*format = ptr;
}

static void	init_types(char **modifier)
{
	modifier[0] = "hh";
	modifier[1] = "h";
	modifier[2] = "l";
	modifier[3] = "ll";
	modifier[4] = "j";
	modifier[5] = "z";
}

char		**init_length_specifiers(void)
{
	char	**tmp;

	tmp = malloc(sizeof(char**) * (6 + 1));
	tmp[6] = 0;
	init_types(tmp);
	return (tmp);
}

int		check_length(char **ref, char *str)
{
	while (*ref)
	{
		if (ft_strstr(*ref, str))
			return (1);
		ref++;
	}
	return (0);
}

// int		check_length(char *str)
// {
// 	if (ft_strstr(str, "ll"))
// 		return (1);
// 	return (0);
// }

void	parse_length(t_data *info, char **format)
{
	char	**ref;
	char	*tmp;
	int		i;

	if (!(*format))
		return ;
	i = 0;
	ref = init_length_specifiers();
	tmp = ft_strdup(*format);
	while (tmp[i] && !check_specifier(tmp[i]))
		i++;
	tmp[i] = '\0';
	if (check_length(ref, tmp))
	{
		info->length = ft_strdup(tmp);
		*format += i;
	}
	else
		info->length = ft_strdup("");
	free(ref);
	free(tmp);
}

int		check_specifier(char c)
{
	char	*list = "sSpdDioOuUxXcC%";
	int		i;

	i = -1;
	while (list[++i])
		if (list[i] == c)
			return (1);
	return (0);
}

void	parse_specifier(t_data *info, char **format)
{
	char	*ptr;

	ptr = *format;
	if (!check_specifier(**format))
		return ;
	info->specifier = *ptr;
	ptr++;
	*format = ptr;
}

void	check_info(t_data *info)
{
	printf("---------------------\n");
	printf("[INFO]\nhex: %d\nzero: %d\n\
minus: %d\nplus: %d\nspace: %d\n\
width: %d\ndot: %d\nprecision: %d\nlength: %s\n\
specifier: %c\n", info->hex, info->zero,
info->minus, info->plus, info->space, info->width, info->dot,
info->precision, info->length, info->specifier);
	printf("----------------------\n");
}

void	handle_mod(char **format, va_list args, int *count)
{
	//%[flags][width][.precision][length]specifier
	char	*ptr;
	t_data	*info;

	ptr = ++(*format);
	info = init_data();
	// check_info(info);
	parse_flags(info, &ptr);
	parse_width(info, &ptr);
	parse_precision(info, &ptr);
	parse_length(info, &ptr);
	parse_specifier(info, &ptr);
	print_format(info, args, count);
	*format = ptr;
	// if (!ft_strequ(info->length, ""))
		free(info->length);
	free(info);
}
