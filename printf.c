#include "main.h"
#include <unistd.h>

/**
 * _printf - custom printf function
 * @format: charcter string composed of 0 or more directives of
 * what _printf should print
 * Return: number of bytes printed excluding the null byte
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0;

	while (format[i] != '\0')
	{
		write(1, format + i, 1);
		i++;
	}
	return (0);
}
