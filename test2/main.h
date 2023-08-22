#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int print_d(va_list list);
int print_rot13(va_list list);
int print_rev(va_list list);
int print_str(va_list list);
int print_char(va_list list);
int _printf(const char*, ...);

#endif
