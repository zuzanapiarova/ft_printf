#include "ft_printf.h"

int main(void)
{
	int a = printf("u:%u\n", -1);
	int b = ft_printf("u:%u\n", -1);
	printf("%d vs %d\n", a, b);
	// check typecasting unsigned values
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
