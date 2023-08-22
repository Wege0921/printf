#include "main.h"

/**
 * get_flags - Extracts active formatting flags from the format string.
 * @format: Formatted string containing the conversion specifier and flags.
 * @i: Current position in the format string.
 * Return: Integer representing the active flags for formatting.
 */
int get_flags(const char *format, int *i)
{
	/* Flags characters: - + 0 # ' ' */
	/* Corresponding values: 1  2  4  8 16 */
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	/* Iterate through characters in the format string */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* Check if the current character is a valid flag character */
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CH[j])
			{
				/* Set the corresponding flag value */
				flags |= FLAGS_ARR[j];
				break;
			}

		/* Stop if an invalid character is encountered */
		if (FLAGS_CH[j] == 0)
			break;
	}

	/* Update the position pointer */
	*i = curr_i - 1;

	return (flags);
}
