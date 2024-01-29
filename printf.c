#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

int handle_fsp(char fsp, size_t slen, va_list args);

/**
 * _printf - writes formatted string to stdout
 * @format: the format string to format and display
 *
 * Return: no of bytes printed or -1 if fail
 */

int _printf(const char *format, ...)
{
	char *fcopy, *parse_str_1, *parse_str_2;
	size_t flen, slen;
	char fsp = '\0';
	va_list args;


	/* IS FORMAT NULL? */
	if (format == NULL)
		return (-1);

	/* CREATE LOCAL COPY OF FORMAT STRING */
	flen = strlen(format);
	fcopy = (char *)malloc(sizeof(char) * flen);
	strcpy(fcopy, format);

	/* CHECK FOR CONVERSION SPECIFIERS? */
	/* First parsing initializes pointer to tokenizer */
	parse_str_1 = strtok(fcopy, "%");
	parse_str_2 = strtok(NULL, "%");

	/* 1-> No conversion specifiers, WRITE TO STDOUT */
	if (parse_str_2 == NULL)
	{
		write(1, fcopy, flen);
		return (flen);
	}

	/* 2-> Conversion specifiers found */

	/* Write text preceding first instance of % to STDOUT */
	slen = strlen(parse_str_1);
	write(1, parse_str_1, slen);
	va_start(args, format);

	while (parse_str_2 != NULL)
	{
		fsp = *parse_str_2;
		slen = handle_fsp(fsp, slen, args);
		flen = strlen(++parse_str_2);
		write(1, parse_str_2, flen);
		slen += flen;
		parse_str_2 = strtok(NULL, "%");
	}
	free(fcopy);
	va_end(args);
	return (slen);
}


/**
 * handle_fsp - handles the format specifier characters
 * @fsp: the format specifier character
 * @slen: the current length of printed bytes
 * @args: list of variable arguments
 *
 * Return: summed number of printed bytes
 */

int handle_fsp(char fsp, size_t slen, va_list args)
{
	char c;
	char *str;
	size_t len;

	switch (fsp)
	{
		case '%':
			write(1, "%", 1);
			slen += 1;
			break;
		case 'c':
			c = va_arg(args, int);
			write(1, &c, 1);
			slen += 1;
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)

			len = strlen(str);
			write(1, str, len);
			slen += len;
			break;
		case 'd':
			break;
		default:
			write(1, "%", 1);
			write(1, &fsp, 1);
			slen += 2;
	}
	return (slen);
}
