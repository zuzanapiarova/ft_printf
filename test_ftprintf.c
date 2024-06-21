#include "ft_printf.h"

int main(void)
{
	int p = 2;
	int a = printf("d:%d\n", p);
	int b = ft_printf("d:%d\n", p);
	printf("%d vs %d\n", a, b);
}
