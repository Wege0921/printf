#include "main.h"

#define BUFFER_SIZE 1024

void flush_buffer(char buffer[], int *buffer_index);

/**
 * _printf - Custom printf function
 * @format: Format string containing directives
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0, chars_printed = 0;
	int flags, width, precision, size, buffer_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
				flush_buffer(buffer, &buffer_index);
			chars_printed++;
		}
		else
		{
			flush_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			i++;
			chars_printed = handle_format(format, &i, args, buffer,
				flags, width, precision, size);
			if (chars_printed == -1)
				return (-1);
			printed_chars += chars_printed;
		}
	}

	flush_buffer(buffer, &buffer_index);

	va_end(args);

	return (printed_chars);
}

/**
 * flush_buffer - Prints the contents of the buffer if it's not empty
 * @buffer: Array of characters
 * @buffer_index: Index to keep track of buffer length
 */
void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, buffer, *buffer_index);
		*buffer_index = 0;
	}
}
