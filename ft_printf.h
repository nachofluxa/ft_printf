#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//ft_printf.c
int	ft_printf(const char *, ...);
int ft_printf2(va_list args, char c, int len);
//ft_printf2.c
char *itoa(int n, int sgn);
char *itoa_hexa(unsigned long int n, char *base);
size_t	len_itoa(int n, int ifhex);
//ft_printf_utils.c
int print_char(char c, int len);
int print_str(char *str, int len);
int print_str2(char *str, int len);
int print_void(void *str, int len);

#endif