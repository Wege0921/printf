#include "main.h"

/**
 * get_precision - Extracts precision information
 *	for printing from the format string.
 * @format: Formatted string containing the
 *	conversion specifier and precision field.
 * @i: Current position in the format string.
 * @list: Variable argument list containing the arguments to be printed.
 *
 * Return: Precision value extracted from the format string.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	/* Check if precision field is present */
	if (format[curr_i] != '.')
		return (precision);

	precision = 0;

	/* Iterate through characters in the format string to extract precision */
	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			/* Get precision value from variable arguments */
			break;
		}
		else
			break;
	}

	/* Update the position pointer */
	*i = curr_i - 1;

	return (precision);
}
