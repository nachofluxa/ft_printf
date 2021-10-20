
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	len;
	size_t i;
	va_list args;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = ft_printf2(args, str[i + 1], len);
			i = i + 2;
		}
		else 
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int ft_printf2(va_list args, char c, int len)
{
	if (c == 'c')
		len = print_char(va_arg(args, int), len);
	else if (c == 's')
		len = print_str(va_arg(args, char *), len);
	else if (c == 'p')
		len = print_void(va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		len = print_str2(itoa(va_arg(args, int), 0), len);
	else if (c == 'u')
		len = print_str2(itoa(va_arg(args, unsigned int), 1), len);
	else if (c == 'x')
		len = print_str2(itoa_hexa(va_arg(args, int),
			"0123456789abcdefg"), len);
	else if (c == 'X')
		len = print_str2(itoa_hexa(va_arg(args, int), 
			"0123456789ABCDEFG"), len);
	else if (c == '%')
	{
		write(1, "%",1);
		len++;
	}
	return (len);
}