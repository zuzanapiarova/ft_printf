/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:08:19 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/21 17:48:54 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_hexadecimal(int num, int base)
{
	char *characters;
	char *result;
	int count;
	int i;
	int numdup;

	i = 0;
	count = 0;
	numdup = num;
	characters = "123456789abcdef";
	while (numdup)
	{
		numdup /= 16;
		count++;
	}
	result =(char *) malloc(count * sizeof(char));
	while (num)
	{
		result[count - i - 1] = characters[num%16 - 1];
		i++;
		num /= 16;
	}
	i = 0;
	while(result[i])
	{
		write(1, &result[i], 1);
		i++;
	}
	free(result);
	return (count);
}

int main(void)
{
	print_hexadecimal(1453, 16);
}
