#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_string - writes a null terminated string to the output stream
 * @args: list of arguments
 *
 * Return: mumber of characters printed
 */

int print_string(va_list args)
{
	char *str;
	int i;

	str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_char - function prints a single character
 *
 * @args: list of arguments
 * Return: number of characters printed
 */

/* writes a single char to the output stream */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);

	return (1);
}

/**
 * print_int - prints an integer
 * @args: list of arguments
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n, count;
	int rev_digits[100];

	n = va_arg(args, int);

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	count = 0;

	do
	{
		rev_digits[count++] = n % 10;
		n = n / 10;
	} while (n > 0);

	while (--count >= 0)
	{
		_putchar('0' + rev_digits[count]);
	}

	return (n);
}