#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* Flags used in formatting */
#define F_MINUS 1   /* Flag for left-aligning content */
#define F_PLUS 2    /* Flag for showing a plus sign for positive numbers */
#define F_ZERO 4    /* Flag for zero-padding */
#define F_HASH 8    /* Flag for including hash/prefix in numeric conversions */
#define F_SPACE 16  /* Flag for inserting a space before positive numbers */

/* Size specifiers */
#define S_LONG 2    /* Size specifier for long data types */
#define S_SHORT 1   /* Size specifier for short data types */

/**
 * struct fmt - Structure for format specifier mapping
 *
 * @fmt: The format specifier character.
 * @fn: The function associated with the format specifier.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Typedef for struct fmt
 *
 * @fmt: The format specifier character.
 * @fn: The function associated with the format specifier.
 */
typedef struct fmt fmt_t;

/* Main printf function */
int _printf(const char *format, ...);

/* Function to handle printing based on format specifier */
int handle_print(const char *fmt, int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size);


/* Functions for printing chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions for printing numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function for printing hexadecimal numbers */
int print_hexa(va_list types, char map_to[],
	char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function for printing non-printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function for printing memory addresses */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions for handling other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* Function for printing string in reverse */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function for printing a string in ROT13 encoding */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler functions */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
	char buffer[], int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif

