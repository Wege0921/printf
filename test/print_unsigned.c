#include "main.h"
/**
 * print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n)
{
	char buffer[10];
	int printed_chars = 0;
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		buffer[i] = n % 10 + '0';
		n /= 10;
		i++;
	}

	while (i > 0)
	{
		write(1, &buffer[i - 1], 1);
		printed_chars++;
		i--;
	}

	return (printed_chars);
}
