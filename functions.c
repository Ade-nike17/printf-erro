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
