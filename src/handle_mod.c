#include "ft_printf.h"

void	handle_mod(char **format, va_list args, int *count)
{
	char	*ptr;
	t_data	*info;

	ptr = ++(*format);
	info = init_data();
	parse_flags(info, &ptr);
	parse_width(info, &ptr);
	parse_precision(info, &ptr);
	parse_length(info, &ptr);
	parse_specifier(info, &ptr);
	print_format(info, args, count);
	*format = ptr;
	free(info->length);
	free(info);
}
