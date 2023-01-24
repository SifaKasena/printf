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
	unsigned int i = 0;
	va_list ptr;
	char c, *s;

	va_start(ptr, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			write(1, format + i, 1);
		else
		{
			i++;
			switch (format[i])
			{
				case '%':
					write(1, format + i, 1);
					break;
				case 'c':
					c = va_arg(ptr, int);
					write(1, &c, 1);
					break;
				case 's':
					s = va_arg(ptr, char *);
					write(1, s, strlen(s) + 1);
					break;
				default:
					break;
			}
		}
		i++;
	}
	va_end(ptr);
	return (0);
}
