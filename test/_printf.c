#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: The variable number of arguments.
 *
 * Return: The number of characters printed.
 */
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 * @...: The variable number of arguments.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
				printed_chars += print_char(va_arg(args, int));
			else if (*format == 's')
				printed_chars += print_string(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				printed_chars += print_number(va_arg(args, int));
			else if (*format == '%')
				printed_chars += print_char('%');
			else if (*format == 'u')
				printed_chars += print_unsigned(va_arg(args, unsigned int));
			else if (*format == 'l')
				printed_chars += print_long(va_arg(args, long));
		}
		else
		{
			printed_chars += print_char(*format);
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}
