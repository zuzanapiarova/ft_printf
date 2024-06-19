/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:01:42 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/20 00:02:37 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>


int print_digit(int num, int base)
{
	int count;

	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		return print_digit(-num, base) + 1;
	}

	return (count);
}
