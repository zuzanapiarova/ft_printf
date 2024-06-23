/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:49:44 by zuzanapiaro       #+#    #+#             */
/*   Updated: 2024/06/23 12:22:05 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

//this function checks the format specifiers cspdiuxX% and calls specific function based on which specifier it gets
//for each different specifier we call designated function with the argument as first parameter
//we get the argument by va_arg which fetches next argument from argument list ap and for this function we also need to specify its DT
// all these functions return number of chars written
int print_format(char format_specifier, va_list ap)
{
	int count;

	count = 0;
	// character - represented as int
	if (format_specifier == 'c')
		count += print_char(va_arg(ap, int)); //data type for char is int because of implicit type conversion to higher DT
	// string
	else if (format_specifier == 's')
		count += print_string(va_arg(ap, char *));
	// prints percent sign
	else if (format_specifier == '%')
		count += print_percent();
	// signed decimal integer - in 10 base
	else if (format_specifier == 'd')
		count += print_digit((long)(va_arg(ap, int))); //typecast int to long to handle minus values
	// signed integer in any base
	else if (format_specifier == 'i')
		count += print_digit((long)(va_arg(ap, int))); //typecast int to long to handle minus values
	// unsigned decimal integer
	else if (format_specifier == 'u')
		count += print_unsigned((unsigned long)(va_arg(ap, unsigned long)));
	// hexadecimal in lowercase - in base 16, prints lowercase letters
	else if (format_specifier == 'x')
		count += print_hexadecimal((long)(va_arg(ap, unsigned int)), 'x'); //for hexadecimals we can use same function as for digit but with type unsigned int and base 16
	// hexadecimal in uppercase - in base 16, prints uppercase letters
	else if (format_specifier == 'X')
		count += print_hexadecimal((long)(va_arg(ap, unsigned int)), 'X'); //for hexadecimals we can use same function as for digit but with type unsigned int and base 16
	// pointer - prints memory address of variable - void * pointer argument has to be printed in hexadecimal format
	else if (format_specifier == 'p')
		count += print_pointer((unsigned long long)va_arg(ap, void *));
	// other unspecified specifiers to handle
	else
		count += write(1, &format_specifier, 1);
	return (count);
}

//this is the main function that iterates the input we received in printf and counts how many arguments there are
//and calls print_format function each time we encounter an argument that is marked with %
//it returns number of characters written, including both normal chars in the input string and argument chars
int	ft_printf(const char *format, ...)
{
	//va_list is DT to store all extra arguments in function call that we do not know how many beforehand
	//ap is arguments pointer that stores all arguments we encounter and initially points to the first argument
	va_list ap;
	int count; //here we store how many arguments we found in function call

	count = 0;
	va_start(ap, format);

	//format is pointer to the input string, and we iterate over it one char at time
	while (*format)
	{
		//when we encounter % we call print_format function because
		//now we know we are on a format specifier because ++format takes us onto character one position after an % sign which is the format specifier
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}

	//va_end is called after we found the last argument to clean up data and know we are finished
	va_end(ap);

	//printf returns how many arguments we encountered in function call
	return (count);
}

//for hexadecimal we use unsigned int because hexadecimal does not go into minus numbers, so to keep the same range needed we put it to unsigned
