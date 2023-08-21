#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
void flush_buffer(char buffer[], int *buffer_index);
int handle_print(const char *fmt, int *ind, va_list list, 
		char buffer[], int flags, int width, int precision, int size);
int print_char(char c);
int print_string(char *str);
int print_number(int n);
int _printf(const char *format, ...);
/**
 * struct fmt - Structure to associate format specifiers with functions
 * @fmt: The format specifier character.
 * @fn: Pointer to the function associated with the format specifier.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt - Typedef for struct fmt
 * @fmt: The format specifier character.
 * @fn: Pointer to the function associated with the format specifier.
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

#endif /* MAIN_H */
