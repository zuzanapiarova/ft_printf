/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:29:46 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/23 11:48:40 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_pointer(void *ptr)
{
	write(1, "0x", 2);
	return print_hexadecimal((unsigned long) ptr, 'x') + 2;
}
