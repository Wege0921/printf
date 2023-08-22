#include "main.h"

/**
 * get_size - Extracts the size specifier from the format string.
 * @format: Formatted string containing the conversion
 *	specifier and optional size specifier.
 * @i: Current position in the format string.
 *
 * Return: Size specifier corresponding to the
 *	argument type, or 0 if none found.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	/* Check for size specifiers */
	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	/* Update the position pointer */
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
