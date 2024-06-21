/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:01:42 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/21 12:08:38 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int print_digit(int num, int base)
{
	int count;
	char *str;

	count = 0;
	str = ft_itoa(num);
	//printf("printing string from print_digit: %s, base: %d\n", str, base);
	count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
