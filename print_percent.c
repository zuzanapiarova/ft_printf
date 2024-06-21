#include "ft_printf.h"
#include <unistd.h>

int print_percent(void)
{
	return write(1, "%", 1);
}
