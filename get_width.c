#include "main.h"

/**
 * get_width - Extracts the width specifier from the format string.
 * @format: Formatted string containing the conversion
 *	specifier and optional width specifier.
 * @i: Current position in the format string.
 * @list: va_list of arguments to be printed.
 *
 * Return: Width specifier for formatting, or 0 if none found.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* If a digit is encountered, calculate width */
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		/* If '*' is encountered, retrieve width from arguments */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		/* If no more width-related characters, exit loop */
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
