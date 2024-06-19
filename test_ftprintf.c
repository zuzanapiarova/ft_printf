#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	int a = printf("%%c %c,  %% hi, s %s hi\n", 'z', "zuzka");
	int b = ft_printf("%%c %c,  %% hi, s %s hi\n", 'z', "zuzka");
	printf("%d vs %d\n", a, b);
}
