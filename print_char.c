
#include "main.h"

/**
 * print_char - Prints a single character
 * @types: Variadic argument list
 * @buffer: Buffer array to handle printing
 * @flags: Flag settings
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
