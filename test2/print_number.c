/* print_number.c */

#include <stdarg.h>
#include "main.h"

/**
 * print_number - Prints an integer.
 *
 * @list: The va_list of arguments
 * Return: The number of characters printed
 */
int print_number(va_list list)
{
	int num = va_arg(list, int);
	int printed_chars = 0;

	if (num < 0)
	{
		printed_chars += print_char('-');
		num = -num;
	}

	printed_chars += print_unsigned((unsigned int)num);

	return (printed_chars);
}

