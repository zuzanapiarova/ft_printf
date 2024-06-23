/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:01:42 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/23 07:37:47 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int print_digit(long num)
{
	int count;
	char *str;

	count = 0;
	str = ft_itoa(num);
	count += ft_strlen(str);
	print_string(str);
	free(str);
	return (count);
}
