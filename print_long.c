#include "main.h"
/**
 * print_long - Prints a long integer.
 * @n: The long integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_long(long n)
{
	char buffer[20];
	int printed_chars = 0;
	int i = 0;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		printed_chars++;
	}

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
