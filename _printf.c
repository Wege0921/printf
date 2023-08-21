#include <stdarg.h>
#include <unistd.h>
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

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int printed_chars = 0;

	while (*str)
	{
		printed_chars += print_char(*str);
		str++;
	}

	return (printed_chars);
}

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
			else if (*format == '%')
				printed_chars += print_char('%');
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
