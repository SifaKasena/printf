#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @n: integer pointer
 * Return: void
 */

void print_char(unsigned int *n, ...)
{
	va_list ptr;
	char c;

	va_start(ptr, n);
	c = va_arg(ptr, int);
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_int - prints an integer
 * @n: integer pointer
 * Return: void
 */

void print_int(unsigned int *n, ...)
{
	va_list ptr;
	int num;
	char c;
	unsigned int u_num;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num < 0)
	{
		c = '-';
		write(1, &c, 1);
		u_num = num * -1;
	}
	else
	{
		u_num = num;
	}
	if (u_num / 10)
		print_int(n, u_num / 10);
	c = u_num % 10 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_str - prints a character string
 * @n: integer pointer
 * Return: void
 */

void print_str(unsigned int *n, ...)
{
	va_list ptr;
	char *s;

	va_start(ptr, n);
	s = va_arg(ptr, char *);
	while (*s != '\0')
	{
		write(1, s, 1);
		(*n)++;
		s++;
	}
	va_end(ptr);
}

/**
 * print_bin - prints a character string
 * @n: integer pointer
 * Return: void
 */

void print_bin(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 2)
		print_bin(n, num / 2);
	c = num % 2 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_uint - prints an unsigned integer
 * @n: integer pointer
 * Return: void
 */
void print_uint(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 10)
		print_uint(n, num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_oct - prints an integer in octal
 * @n: integer pointer
 * Return: void
 */
void print_oct(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 8)
		print_oct(n, num / 8);
	c = num % 8 + '0';
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_hex - prints an integer in lower case hexadecimal
 * @n: integer pointer
 * Return: void
 */
void print_hex(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 16)
		print_hex(n, num / 16);
	c = num % 16 < 9 ? num % 16 + '0' : num % 16 + 87;
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_hex_caps - prints an integer in upper case hexadecimal
 * @n: integer pointer
 * Return: void
 */
void print_hex_caps(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 16)
		print_hex_caps(n, num / 16);
	c = num % 16 < 9 ? num % 16 + '0' : num % 16 + 55;
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}

/**
 * print_adr - prints an address
 * @n: integer pointer
 * Return: void
 */
void print_adr(unsigned int *n, ...)
{
	va_list ptr;
	unsigned int num;
	char c;
	char *s = "0x7ffe";

	va_start(ptr, n);
	num = va_arg(ptr, int);
	if (num / 16)
		print_adr(n, num / 16);
	else
		print_str(n, s);
	c = num % 16 < 9 ? num % 16 + '0' : num % 16 + 87;
	write(1, &c, 1);
	(*n)++;
	va_end(ptr);
}
