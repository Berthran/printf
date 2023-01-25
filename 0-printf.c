#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * print_count_char - writes the character c to stdout and counts it
 * @c: The character to print
 *
 * Return: 1
 */

int print_count_char(char c)
{
	int char_counter = 0;

	if (c != '%')
	{
		_putchar(c);
		++char_counter;
	}
	return (char_counter);
}

/**
 * print_count_str - writes characters to stdout and counts each one
 * @ptr_str: The characters to print
 *
 * Return: number of characters counted
 */

int print_count_str(char *ptr_str)
{
	int char_counter = 0;

	while (*ptr_str)
	{
		_putchar(*ptr_str);
		++char_counter;
		++ptr_str;
	}
	return (char_counter);
}

/**
 * print_count_nxarg - write chars in next arg to stdout and counts them
 * @format: the current position of the pointer to the string
 * @ap: argument list passed to the _printf function
 *
 * Return: number of characters printed from the next argument
 */

int print_count_nxarg(const char *format, va_list ap)
{
	int cval;
	char *str;
	char *null_str = "(null)";
	int char_counter = 0;

	switch (*++format) /* go to next character */
	{
		case '%':
			_putchar('%');
			++char_counter;
			break;
		case 'c':
			cval = va_arg(ap, int);
			char_counter += print_count_char(cval);
			break;
		case 's':
			str = va_arg(ap, char *);
			if (str == NULL)
				char_counter += print_count_str(null_str);
			else
				char_counter += print_count_str(str);
			break;
		default:
			if (*format == '\0')
				return (-1);
			_putchar(*--format);
			_putchar(*++format);
			char_counter += 2;
			break;
	}
	return (char_counter);
}

/**
 * _printf - writes a formated string to stdout and counts it
 * @format: the string to format
 *
 * Return: number of characters printed from the next argument
 */

int _printf(const char *format, ...)
{
	int char_counter;
	va_list ap;

	char_counter = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		/* Capture conversion specifier*/
		if (*format == '%')
		{
			char_counter += print_count_nxarg(format, ap);
			++format;
			if (*format == '\0')
				return (char_counter);
		}
		else
		{
			char_counter += print_count_char(*format);
		}
		++format;
		va_end(ap);
	}
	return (char_counter);
}
