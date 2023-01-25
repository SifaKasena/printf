#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @n: integer pointer
 * @c: character to print
 * Return: void
 */

void print_char(unsigned int *n, int c)
{
	write(1, &c, 1);
	(*n)++;
}

/**
 * print_int - prints an integer
 * @n: integer pointer
 * @num: number to print
 * Return: void
 */

void print_int(unsigned int *n, int num)
{
	char c;

	if (num / 10)
		print_int(n, num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	(*n)++;
}

/**
 * print_str - prints a character string
 * @n: integer pointer
 * @s: string to print
 * Return: void
 */

void print_str(unsigned int *n, char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		(*n)++;
		s++;
	}
}
