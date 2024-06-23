/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:08:19 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/23 09:45:08 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hexadecimal(long num, char c)
{
	char *characters;
	char *result;
	int count;
	int i;
	long long numdup;

	i = 0;
	count = 0;
	numdup = num;
	characters = "0123456789abcdef";
	if (c  == 'X')
		characters = "0123456789ABCDEF";
	while (numdup)
	{
		numdup /= 16;
		count++;
	}
	if (num == 0)
		return (write(1, "0", 1));
	result =(char *) malloc(count * sizeof(char));
	if (!result)
		return 0;
	while (num)
	{
		result[count - i - 1] = characters[num%16];
		i++;
		num /= 16;
	}
	print_string(result);
	free(result);
	return (count);
}

// int main(void)
// {
// 	print_hexadecimal(1456, 16); //5ad / 5AD
// }
