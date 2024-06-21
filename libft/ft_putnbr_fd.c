/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:24:24 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/20 15:48:06 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
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

void ft_putnbr_fd(int n, int fd)
{
	char *num;
	char *num_start;

	num = ft_itoa(n);
	num_start = num;
	while(*num)
	{
		write(fd, num, 1);
		num++;
	}
	free(num_start);
}
