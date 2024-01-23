/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifluxa-c <ifluxa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:16:11 by ifluxa-c          #+#    #+#             */
/*   Updated: 2021/11/02 18:13:36 by ifluxa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

//ft_printf.c
int					ft_printf(const char *str, ...);
int					ft_printf2(va_list args, char c, int len);
//ft_printf2.c
char				*itoa(int n);
char				*itoa_hexa(unsigned long int n, char *base, int if_void);
unsigned int		len_itoa(int n);
unsigned long int	len_itoa_hexa(unsigned long int n);
char				*itoa_unsigned(unsigned int n);
//ft_printf_utils.c
int					print_char(char c, int len);
int					print_str(char *str, int len);
int					print_str2(char *str, int len);
int					print_void(void *str, int len, int type);

#endif