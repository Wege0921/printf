#include "main.h"

/**
 * handle_print - Handles the printing of an argument based on
 *	its format specifier.
 * @fmt: Formatted string containing the conversion specifier and
 *	optional width and precision specifiers.
 * @ind: Pointer to the current position in the format string.
 * @list: va_list of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags for formatting.
 * @width: Width specification for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for data types.
 *
 * This function processes the format specifier in @fmt and
 *	directs the printing to the appropriate
 * formatting function for the corresponding data type.
 *	If the format specifier is not recognized,
 *	it prints the specifier as is.
 *	Handles various formatting options such as width and precision.
 *
 * Return: Number of characters printed, or -1 if an unrecognized
 *	format specifier is encountered.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;

	/* Array of supported format types and their corresponding functions */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	/* Find the matching format type and call its corresponding function */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	/* If no recognized format type is found */
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);

		/* Print unrecognized specifier */
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}

	return (printed_chars);
}
