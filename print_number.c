#include "main.h"

/**
 * print_number - Prints a number.
 * @n: The number to print.
 *
 * Return: The number of characters printed.
 */
int print_number(int n)
{
	int printed_chars = 0;
	int num = n;

	if (num < 0)
	{
		num = -num;
		printed_chars += print_char('-');
	}

	if (num / 10)
		printed_chars += print_number(num / 10);

	printed_chars += print_char((num % 10) + '0');

	return (printed_chars);
}
