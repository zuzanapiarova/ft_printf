#include "ft_printf.h"

int main(void)
{
	long p = LONG_MIN;
	int a = printf("p:%p\n", &p);
	int b = ft_printf("p:%p\n", &p);
	printf("%d vs %d\n", a, b);
	// // check typecasting unsigned values
	// unsigned int plusone = 1;
	// int minusone = -1;
	// printf("d>> %u, %u\n", plusone, minusone);
	// ft_printf("d>> %u, %u\n", plusone, minusone);
	// check string output of printf
	//int a = printf("str %s\n", NULL);
	//int b = ft_printf("str %s\n", NULL);
	//printf("%d\n", a);
	return 0;
}
