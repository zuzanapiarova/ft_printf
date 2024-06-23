/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:29:46 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/23 12:21:34 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int print_pointer(void *ptr)
{
	write(1, "0x", 2);
	return print_hexadecimal((unsigned long) ptr, 'x') + 2;
}

// int main()
// {
//     long max_value = LONG_MIN;
//     printf("printf: %p\n", (void *)max_value);
//     print_pointer((void *)max_value);
//     return 0;
// }
