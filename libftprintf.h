#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H
#include <string.h>
#include <stddef.h>
//#include "libft.h"

int print_char(char c);
int print_string(char *str);
int print_digit(int num, int base);
int print_pointer();
int print_percent(void);
int	ft_printf(const char *format, ...);


#endif
