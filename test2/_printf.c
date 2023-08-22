#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * handle_conversion - Handle conversion specifier
 *
 * @specifier: The conversion specifier character
 * @list: The va_list of arguments
 * Return: The number of characters printed
 */
int handle_conversion(char specifier, va_list list)
{
	set arguments[] = {
		{'c', print_char},
		{'d', print_d},
		{'i', print_d},
		{'s', print_str},
		{'R', print_rot13},
		{'r', print_rev},
	};
	int j, count = 0;

	for (j = 0; j < 6; j++)
	{
		if (specifier == arguments[j].spec)
		{
			count += arguments[j].print(list);
			return (count);
		}
	}

	return (count);
}

/**
 * _printf - printf function
 *
 * @format: formatted string
 * Return: The total number of outputted characters
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				continue;

			count += handle_conversion(format[i + 1], list);
			i++;
		}
		else
		{
			count += write(1, &format[i], 1);
		}
	}
	va_end(list);

	return (count);
}

