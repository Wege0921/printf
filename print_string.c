#include "main.h"

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		printed_chars += print_char(*str);
		str++;
	}

	return (printed_chars);
}
