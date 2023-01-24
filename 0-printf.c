#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * _printf - a prototype of C printf()
 * @format: a string pointer spcifying printing format
 * Returns: number of printed characters
 */

int _printf(const char *format, ...)
 {
     int char_counter, cval;
     long unsigned int i;
     char *str;
     va_list ap;
 
     char_counter = 0;
 
     if (format != NULL) /*First condition to format display*/
     {
         va_start(ap, format);
         while (*format != '\0')
         {
             /* Capture conversion specifier*/
             if (*format == '%')
             {
                 switch (*++format) /* go to next character */
                 {
                 case 'c':
                     cval = va_arg(ap, int);
                     _putchar(cval);
                     ++char_counter;
                     break;
                 case 's':
                     str = va_arg(ap, char *);
                     for (i = 0; i < strlen(str); i++)
                     {
                         _putchar(str[i]);
                         ++char_counter;
                     }
                     break;
                 default:
                     _putchar(*format);
                     ++char_counter;
                     break;
                 }
                 va_end(ap);
             }
 
             /* Capture escape sequence - next line only */
             else if (*format == '\n')
             {
                 _putchar(*format);
                 ++char_counter;
             }
 
             /* Capture ordinary characters */
             else
             {
                 _putchar(*format);
                 ++char_counter;
             }
             ++format;
         }
         return (char_counter);
     }
     return (-1);
 }
