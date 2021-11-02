/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:13:43 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/02 18:06:45 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c, int len)
{
	write(1, &c, 1);
	len++;
	return (len);
}

int	print_str(char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		len = len + 6;
	}
	else
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
	}
	return (len);
}

int	print_str2(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	free(str);
	return (len);
}

int	print_void(void *str, int len, int type)
{
	unsigned long int	aux;
	char				*aux2;

	aux2 = NULL;
	aux = (unsigned long int)str;
	if (type == 0)
		aux2 = itoa_hexa(aux, "0123456789abcdefg", 0);
	else if (type == 1)
		aux2 = itoa_hexa(aux, "0123456789abcdefg", 1);
	else if (type == 2)
		aux2 = itoa_hexa(aux, "0123456789ABCDEFG", 1);
	if (aux2 && type == 0)
	{
		write(1, "0x", 2);
		len = len + 2;
	}
	len = print_str2(aux2, len);
	return (len);
}
