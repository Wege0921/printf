#include "main.h"

/**
 * print_char - Prints a single character.
 * @c: The character to print.
 *
 * Return: The number of characters printed.
 */
int print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
