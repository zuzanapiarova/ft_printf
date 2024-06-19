#include "libftprintf.h"

int print_string(char *str)
{
	int count;

	count = 0;
	while(*str)
	{
		print_char((int)*str); //typecast to int as chars are interpreted by printf as ints
		++count;
		++str;
	}

	return (count);
}
