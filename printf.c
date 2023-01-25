#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - custom printf function
 * @format: charcter string composed of 0 or more directives of
 * what _printf should print
 * Return: number of bytes printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	unsigned int n, i;
	va_list ptr;

	n = i = 0;
	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			write(1, format + i, 1);
			n++;
		}
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					write(1, format + i, 1);
					break;
				case 'c':
					print_char(&n, va_arg(ptr, int));
					break;
				case 's':
					print_str(&n, va_arg(ptr, char *));
					break;
				case 'd':
				case 'i':
					print_int(&n, va_arg(ptr, int));
					break;
				default:
					write(1, format + i - 1, 2);
					break;
			}
		}
		i++;
	}
	va_end(ptr);
	return (n);
}
