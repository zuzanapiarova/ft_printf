/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:59:45 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/10 12:22:13 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <limits.h>

char *ft_itoa(int n)
{
	unsigned int i;
	int sign;
	char * result;
	int length;
	unsigned int num;

	length = 0;
	sign = 1;
	if(n == 0)
	{
		result = (char *)malloc(2);
		if(!result)
			return NULL;
		result[0] = '0';
		result[1] = '\0';
		return result;
	}
	if(n < 0)
	{
		sign *= -1;
		num = (unsigned int) (-n);
		n *= -1;
		length++;
	}
	else
		num = (unsigned int) n;
	i = num;
	while(i > 0)
	{
		i = i / 10;
		length++;
	}
	if(sign < 0)
		result = (char *)malloc((length * sizeof(char)));
	else
		result = (char *)malloc((length * sizeof(char)));
	if(!result)
		return NULL;
	result[length] = '\0';
	while(length > 0)
	{
		result[length - 1] = num % 10 + '0';
		num = num / 10;
		length--;
	}
	if(sign < 0)
		result[0] = '-';
	return result;
}

// int main(void)
// {
// 	int n = INT_MIN;
// 	printf("result: %s\n", ft_itoa(n));
// }
