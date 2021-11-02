/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:17:52 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/02 18:02:36 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa(int n)
{
	char				*str;
	unsigned int		i;
	unsigned int		l;

	i = len_itoa(n);
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		l = n * -1;
	}
	else
		l = n;
	while (i > 0 && l > 9)
	{
		str[i] = (l % 10) + '0';
		l = l / 10;
		i--;
	}
	str[i] = l + '0';
	return (str);
}

char	*itoa_unsigned(unsigned int n)
{
	char			*str;
	int				i;
	unsigned int	l;

	i = 0;
	l = n;
	if (l == 0)
		i++;
	while (l != 0)
	{
		l = l / 10;
		i++;
	}
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = '\0';
	while (i > 0 && n > 9)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

char	*itoa_hexa(unsigned long int n, char *base, int if_void)
{
	unsigned long int	i;
	char				*str;

	if (if_void == 0)
		i = len_itoa_hexa(n);
	else
		i = (unsigned int)len_itoa_hexa((unsigned int)n);
	str = (char *)malloc (i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (i > 0 && n > 15)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	str[i--] = base[n % 16];
	return (str);
}

unsigned int	len_itoa(int n)
{
	unsigned int	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

unsigned long int	len_itoa_hexa(unsigned long int n)
{
	unsigned long int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}
