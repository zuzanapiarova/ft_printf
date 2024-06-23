#include "ft_printf.h"

int print_string(char *str)
{
	int count;

	if (!str)
		return (write(1, "(null)", 6));
	count = ft_strlen(str);
	write(1, str, count);
	return (count);
}
