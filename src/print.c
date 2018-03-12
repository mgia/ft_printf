#include "ft_printf.h"

// s S p d D i o O u U x X c C
char	*pad_left(char **str, int n, char c)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	char	*tmp2;

	i = 0;
	j = 0;
	tmp2 = *str;
	len = ft_strlen(*str);
	if (n <= len)
		return (*str);
	tmp = ft_strnew(n);
	while (i < (n - len))
		tmp[i++] = c;
	while (i < n)
		tmp[i++] = tmp2[j++];
	free(tmp2);
	return (tmp);
}

char	*pad_right(char **str, int n, char c)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	char	*tmp2;

	i = 0;
	j = 0;
	tmp2 = *str;
	len = ft_strlen(*str);
	if (n <= len)
		return (*str);
	tmp = ft_strnew(n);
	while (str[j])
		tmp[i++] = tmp2[j++];
	while (i < n)
		tmp[i++] = c;
	free(tmp2);
	return (tmp);
}
//
// char	*slice_left(char *str, int n)
// {
// 	int		i;
// 	int		len;
// 	char	*tmp;
//
// 	i = 0;
// 	len = ft_strlen(str);
// 	if (n >= len)
// 		return ("");
// 	tmp = ft_strnew(len - n);
// 	while (str[n])
// 		tmp[i++] = str[n++];
// 	// free(str);
// 	return (tmp);
// }
//
// char	*slice_right(char *str, int n)
// {
// 	int		i;
// 	int		len;
// 	char	*tmp;
//
// 	i = 0;
// 	len = ft_strlen(str);
// 	if (n >= len)
// 		return ("");
// 	tmp = ft_strnew(len - n);
// 	while (i < (len - n))
// 	{
// 		tmp[i] = str[i];
// 		i++;
// 	}
// 	// free(str);
// 	return (tmp);
// }
//
// char	*get_s(t_data *info, va_list args)
// {
// 	char	*str;
// 	wchar_t	*tmp;
// 	int		len;
//
// 	if (info->specifier == 'S' || !ft_strcmp(info->length, "l"))
// 	{
// 		len = 0;
// 		tmp = va_arg(args, wchar_t *);
// 		while (tmp[len])
// 			len++;
// 		len = 0;
// 		str = ft_strnew(len);
// 		while (*tmp)
// 			str[len++] = *tmp++;
// 	}
// 	else
// 		str = va_arg(args, char *);
// 	return (str);
// }
//
// void	print_s(t_data *info, va_list args, int *count)
// {
// 	char	*str;
// 	int		len;
//
// 	str = get_s(info, args);
// 	if (!str)
// 	{
// 		ft_putstr("(null)");
// 		*count += 6;
// 		return ;
// 	}
// 	len = ft_strlen(str);
// 	if (info->dot && info->precision < len)
// 		str = slice_right(str, len - info->precision);
// 	if (info->minus)
// 		str = pad_right(str, info->width, ' ');
// 	else
// 		str = pad_left(str, info->width, ' ');
// 	*count += ft_strlen(str);
// 	ft_putstr(str);
// }
//
// // void	print_p(t_data *info, va_list args, int *count)
// void	print_p(va_list args, int *count)
// {
// 	char *addr;
// 	char *ret;
//
// 	addr = va_arg(args, char *);
// 	ret = ft_strjoin("0x", ft_itoa_base((unsigned long int)addr, 16));
//
// 	ft_putstr(ret);
// 	*count += ft_strlen(ret);
// }
//
// void	print_n_chars(char c, int n, int *count)
// {
// 	*count += n;
// 	while (n--)
// 		ft_putchar(c);
// }
//
// int		init_nbr_params(t_data *info, intmax_t num, int *len, int *p)
// {
// 	int n;
//
// 	if (num < 0)
// 		(*len)--;
// 	if (info->precision > *len)
// 		*p = info->precision - *len;
// 	else
// 		*p = 0;
// 	n = info->width - *len - *p;
// 	if (info->plus || info->space || num < 0)
// 		n--;
// 	return ((n > 0) ? n : 0);
// }
//
// void	print_d(t_data *info, va_list args, int *count)
// {
// 	intmax_t	num;
// 	char	*str;
// 	int		tmp;
//
// 	num = 0;
// 	if (info->specifier == 'D' || ft_strequ(info->length, "l"))
// 		num = va_arg(args, long);
// 	else if (ft_strequ(info->length, "ll"))
// 		num = va_arg(args, long long);
// 	else if (ft_strequ(info->length, "ll"))
// 		num = va_arg(args, long long);
// 	else if (ft_strequ(info->length, "h"))
// 		num = (short int)va_arg(args, int);
// 	else if (ft_strequ(info->length, "hh"))
// 		num = (char)va_arg(args, int);
// 	else if (ft_strequ(info->length, "z"))
// 		num = va_arg(args, size_t);
// 	else if (ft_strequ(info->length, "j"))
// 		num = va_arg(args, intmax_t);
// 	else
// 		num = va_arg(args, int);
//
// 	str = ft_itoa(num);
// 	tmp = 0;
//
// 	if (num < 0)
// 		str++;
//
// 	if (info->precision)
// 		str = pad_left(str, info->precision, '0');
//
// 	if (num < 0 || info->plus || info->space)
// 		tmp++;
//
// 	if (!info->minus && info->zero && !info->dot)
// 		str = pad_left(str, info->width - tmp, '0');
//
// 	if (num < 0)
// 		str = ft_strjoin("-", str);
// 	else if (info->plus)
// 		str = ft_strjoin("+", str);
// 	else if (info->space)
// 		str = ft_strjoin(" ", str);
//
// 	if (info->dot && !info->precision && !num)
// 		str = ft_strdup("");
//
// 	if (info->minus)
// 		str = pad_right(str, info->width, ' ');
// 	else
// 		str = pad_left(str, info->width, ' ');
//
// 	ft_putstr(str);
// 	*count += ft_strlen(str);
// }
//
// char	*u_precision(t_data *info, char	*str)
// {
// 	int		len;
//
// 	len = ft_strlen(str);
// 	// printf("len: %d\n", len);
// 	if (info->dot)
// 	{
// 		if (!info->precision)
// 		{
// 			if (ft_strcmp(str, "0"))
// 				return (ft_strdup(""));
// 			str[0] = '\0';
// 		}
// 		// else if ()
// 		else if (len < info->precision)
// 		{
// 			str = pad_left(str, info->precision, '0');
// 			// printf("tmp: %s\n", str);
// 		}
// 	}
// 	return (str);
// }
//
// char	*u_width(t_data *info, char *tmp)
// {
// 	if (info->width)
// 	{
// 		if (info->minus)
// 			tmp = pad_right(tmp, info->width, ' ');
// 		else if (info->zero)
// 			tmp =pad_left(tmp, info->width, '0');
// 		else
// 			tmp = pad_left(tmp, info->width, ' ');
// 	}
// 	return (tmp);
// }
//
//
// void	print_u(t_data *info, va_list args, int *count)
// {
// 	uintmax_t	num;
// 	char		*str;
//
// 	num = 0;
// 	if (info->specifier == 'U' || ft_strequ(info->length, "l"))
// 		num = va_arg(args, unsigned long);
// 	else if (ft_strequ(info->length, "ll"))
// 		num = va_arg(args, unsigned long long);
// 	else if (ft_strequ(info->length, "h"))
// 		num = va_arg(args, unsigned int) & 0xFFFF;
// 	else if (ft_strequ(info->length, "hh"))
// 		num = va_arg(args, unsigned int) & 0xFF;
//  	else if (ft_strequ(info->length, "z"))
// 		num = va_arg(args, size_t);
// 	else if (ft_strequ(info->length, "j"))
// 		num = va_arg(args, uintmax_t);
// 	else
// 		num = va_arg(args, unsigned int);
// 	// printf("num before: %lu", num);
// 	// str = ul_toa(num);
// 	str = ft_itoa_base(num, 10);
// 	str = u_precision(info, str);
// 	// printf("after precision: %s\n", str);
// 	str = u_width(info, str);
// 	// printf("after width outside: %s", str);
// 	*count += ft_strlen(str);
// 	ft_putstr(str);
// }
//
// void	print_o(t_data *info, va_list args, int *count)
// {
// 	// int		len;
// 	long	num;
// 	char	*str;
// 	int		tmp;
//
// 	num = 0;
// 	tmp = 0;
// 	if (ft_strequ(info->length, "l"))
// 		num = va_arg(args, unsigned long);
// 	else if (ft_strequ(info->length, "ll"))
// 		num = va_arg(args, unsigned long long);
// 	else if (ft_strequ(info->length, "h"))
// 		num = va_arg(args, unsigned int) & 0xFFFF;
// 	else if (ft_strequ(info->length, "hh"))
// 		num = va_arg(args, unsigned int) & 0xFF;
// 	else if (ft_strequ(info->length, "z"))
// 		num = va_arg(args, size_t);
// 	else if (ft_strequ(info->length, "j"))
// 		num = va_arg(args, uintmax_t);
// 	else
// 		num = va_arg(args, unsigned int);
//
// 	str = ft_itoa_base(num, 8);
// 	// octal = get_octal(info, num, &len);
// 	// printf("info->width: %d\n",info->width);
// 	if (info->dot && !info->precision && !num)
// 	{
// 		if (info->hex)
// 			str = ft_strdup("0");
// 		else
// 			str = ft_strdup("");
// 	}
// 	if (info->hex)
// 		tmp = 1;
// 	if (info->precision)
// 		str = pad_left(str, info->precision - tmp, '0');
// 	if (!info->minus && info->zero)
// 		str = pad_left(str, info->width, '0');
// 	if (info->hex && num)
// 			str = ft_strjoin("0", str);
// 	if (info->minus)
// 		str = pad_right(str, info->width, ' ');
// 	else
// 		str = pad_left(str, info->width, ' ');
//
// 	*count += ft_strlen(str);
// 	ft_putstr(str);
// }
//
// void	ft_strupper(char *str)
// {
// 	if (!str)
// 		return ;
// 	while (*str)
// 	{
// 		*str = ft_toupper(*str);
// 		str++;
// 	}
// }
//
// void	print_x(t_data *info, va_list args, int *count)
// {
// 	uintmax_t	num;
// 	char		*str;
// 	int			tmp;
//
// 	num = 0;
// 	tmp = 0;
// 	if (ft_strequ(info->length, "l"))
// 		num = va_arg(args, unsigned long);
// 	else if (ft_strequ(info->length, "ll"))
// 		num = va_arg(args, unsigned long long);
// 	else if (ft_strequ(info->length, "h"))
// 		num = va_arg(args, unsigned int) & 0xFFFF;
// 	else if (ft_strequ(info->length, "hh"))
// 		num = va_arg(args, unsigned int) & 0xFF;
// 	else if (ft_strequ(info->length, "z"))
// 		num = va_arg(args, size_t);
// 	else if (ft_strequ(info->length, "j"))
// 		num = va_arg(args, uintmax_t);
// 	else
// 		num = va_arg(args, unsigned int);
//
// 	str = ft_itoa_base(num, 16);
// 	if (info->dot && !info->precision && !num)
// 		str = ft_strdup("");
// 	else if (info->hex)
// 		tmp = 2;
// 	if (info->minus)
// 		str = pad_right(str, info->width - tmp, ' ');
// 	else if (info->zero)
// 		str = pad_left(str, info->width - tmp, '0');
// 	if (info->hex && num)
// 	{
// 		if (info->specifier == 'x')
// 			str = ft_strjoin("0x", str);
// 		else
// 			str = ft_strjoin("0X", str);
// 	}
// 	if (!(info->minus && info->zero))
// 		str = pad_left(str, info->width, ' ');
// 	*count += ft_strlen(str);
// 	if (info->specifier == 'X')
// 		ft_strupper(str);
// 	ft_putstr(str);
// }
//
int		print_null(t_data *info, int *count)
{
	char		c;

	c = 0;
	if (!info->minus)
	{
		while (--info->width > 0 && ++(*count))
			ft_putchar(' ');
		write(1, &c, 1);
		(*count)++;
	}
	else if (info->minus)
	{
		write(1, &c, 1);
		(*count)++;
		while (--info->width > 0 && ++(*count))
			ft_putchar(' ');
	}
	return (1);
}

void	print_c(t_data *info, va_list args, int *count)
{
	uintmax_t	c;
	char	*str;

	str = ft_strnew(1);
	if (info->specifier == 'C' || !ft_strcmp(info->length, "l") ||
		!ft_strcmp(info->length, "ll"))
		c = (wchar_t)va_arg(args, void *);
	else
		c = (char)va_arg(args, void *);
	if (!c)
	{
		print_null(info, count);
		return ;
	}
	str[0] = c;
	if (info->minus && info->width)
		str = pad_right(&str, info->width, ' ');
	else if (info->width)
		str = pad_left(&str, info->width, ' ');
	*count += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	print_mod(t_data *info, int *count)
{
	char	*str;

	str = "%";
	if (info->minus)
		str = pad_right(&str, info->width, ' ');
	else if (info->zero)
		str = pad_left(&str, info->width, '0');
	else
		str = pad_left(&str, info->width, ' ');
	*count += ft_strlen(str);
	ft_putstr(str);
	free(str);
}

void	print_format(t_data *info, va_list args, int *count)
{
	// if (info->specifier == 's' || info->specifier == 'S')
	// 	print_s(info, args, count);
	// else if (info->specifier == 'p')
	// 	print_p(args, count);
	// else if (info->specifier == 'd' || info->specifier == 'D' ||
	// 		info->specifier == 'i')
	// 	print_d(info, args, count);
	// else if (info->specifier == 'o' || info->specifier == 'O')
	// 	print_o(info, args, count);
	// else if (info->specifier == 'u' || info->specifier == 'U')
	// 	print_u(info, args, count);
	// else if (info->specifier == 'x' || info->specifier == 'X')
	// 	print_x(info, args, count);
	if (info->specifier == 'c' || info->specifier == 'C')
		print_c(info, args, count);
	else if (info->specifier == '%')
		print_mod(info, count);
}
