#include "main.h"

/**
 * is_printable - Check if a character is printable
 * @c: The character to be checked
 *
 * Return: 1 if the character is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of characters to append to
 * @i: Starting index for appending
 * @ascii_code: ASCII code to be appended
 *
 * Return: The number of characters appended (always 3)
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Check if a character is a digit
 * @c: The character to be checked
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Convert a number to the specified size
 * @num: The number to be converted
 * @size: The target size for conversion (S_LONG or S_SHORT)
 *
 * Return: The converted value of num with the specified size
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Convert an unsigned number to the specified size
 * @num: The number to be converted
 * @size: The target size for conversion (S_LONG or S_SHORT)
 *
 * Return: The converted value of num with the specified size
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
