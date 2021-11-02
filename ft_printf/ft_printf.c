/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:14:33 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/02 18:10:54 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	i;
	va_list	args;

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
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}

int	ft_printf2(va_list args, char c, int len)
{
	if (c == 'c')
		len = print_char(va_arg(args, int), len);
	else if (c == 's')
		len = print_str(va_arg(args, char *), len);
	else if (c == 'p')
		len = print_void(va_arg(args, void *), len, 0);
	else if (c == 'd' || c == 'i')
		len = print_str2(itoa(va_arg(args, int)), len);
	else if (c == 'u')
		len = print_str2(itoa_unsigned(va_arg(args, unsigned int)), len);
	else if (c == 'x')
		len = print_void(va_arg(args, void *), len, 1);
	else if (c == 'X')
		len = print_void(va_arg(args, void *), len, 2);
	else if (c == '%')
	{
		write(1, "%", 1);
		len++;
	}
	return (len);
}
