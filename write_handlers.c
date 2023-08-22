#include "main.h"

/**
 * handle_write_char - Handles printing a single character
 *	with specified formatting.
 * @c: The character to be printed.
 * @buffer: Buffer array used for handling print operations.
 * @flags: Active formatting flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * This function takes a character and formats it
 *	based on the provided specifications.
 * It handles padding and alignment as defined by
 *	the flags, width, and precision.
 * The result is stored in the buffer, and
 *	the number of characters printed is returned.
 *
 * Return: Number of characters printed.
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Initialize variables */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	/* Determine padding character based on flags */
	if (flags & F_ZERO)
		padd = '0';

	/* Store the character in the buffer */
	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		/* Handle width and padding */
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		/* Determine the order of printing based on flags */
		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	/* Printing the character */
	return (write(1, &buffer[0], 1));
}


/**
 * write_number - Writes a formatted number to the buffer.
 * @is_negative: Determines if the number is negative.
 * @ind: Index where the number starts in the buffer.
 * @buffer: Buffer array to handle print.
 * @flags: Active formatting flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Calculate the length of the number in the buffer */
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	/* Determine padding and extra characters based on formatting flags */
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	/* Call write_num function to handle formatting and printing */
	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

/**
 * write_num - Writes a formatted number to the buffer.
 * @ind: Index where the number starts in the buffer.
 * @buffer: Buffer array to handle print.
 * @flags: Active formatting flags.
 * @width: Width specification.
 * @prec: Precision specifier.
 * @length: Number length.
 * @padd: Padding character.
 * @extra_c: Extra character.
 *
 * Return: Number of printed characters.
 */


int write_num(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* Extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}


/**
 * write_unsgnd - Writes an unsigned number with formatting options.
 * @is_negative: Flag indicating if the number is negative.
 * @ind: Index at which the number starts in the buffer.
 * @buffer: Array of characters to store the formatted output.
 * @flags: Formatting flags indicating special behaviors.
 * @width: Width specifier for minimum width of output.
 * @precision: Precision specifier for controlling number of digits.
 * @size: Size specifier for handling different data sizes.
 *
 * Return: Number of written characters.
 */

int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* The number is stored at the buffer's right and starts at position 'ind' */
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	/* Handle cases where no characters are printed */
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	/* Adjust padding and length based on precision */
	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	/* Set padding character based on formatting flags */
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	/* Handle padding based on width */
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';
		/* Handle alignment based on formatting flags */
		if (flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Assign extra characters to left of padding */
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}	return (write(1, &buffer[ind], length));
}
/**
 * write_pointer - Writes a formatted memory address.
 * @buffer: Array of characters to store the formatted output.
 * @ind: Index where the number starts in the buffer.
 * @length: Length of the address number.
 * @width: Minimum width specifier for output.
 * @flags: Formatting flags controlling special behaviors.
 * @padd: Character representing the padding.
 * @extra_c: Character representing extra characters.
 * @padd_start: Index at which padding should start.
 *
 * Return: Number of written characters.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
