/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 09:19:13 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/23 11:15:57 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	char	*result;
	unsigned int	i;
	int length;

	i = num;
	length = 0;
	while(i > 0)
	{
		i = i / 10;
		length++;
	}
	if (num == 0)
	{
		result = (char *)malloc(2 * sizeof(char));
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result = (char *)malloc(length * sizeof(char));
	if (!result)
		return (NULL);
	result[length] = '\0';
	while(length > 0)
	{
		result[length - 1] = num % 10 + '0';
		num /= 10;
		length--;
	}
	return (result);
}

int print_unsigned(unsigned long num)
{
	int count;
	char *str;

	count = 0;
	str = ft_utoa(num);
	count += ft_strlen(str);
	print_string(str);
	free(str);
	return (count);
}

// int main(void)
// {
// 	print_unsigned(-1);
// }
