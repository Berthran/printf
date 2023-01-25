#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>

int _putchar(char c);

int print_count_char(char c);

int print_count_str(char *ptr_str);

int print_count_nxarg(const char *format, va_list ap);

int _printf(const char *format, ...);

#endif
