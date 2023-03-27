#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * write_char - function prints a single character
 *
 * @c: character to be printed
 * @num: pointer to an int var that tracks number of characters to be printed
 *
 * Return: nothing
 */

/* writes a single char to the output stream */
void write_char(char c, int *num)
{
	if (num != NULL)
	{
		_putchar(c);
		(*num)++;
	}
}

/**
 * write_string - writes a null terminated string to the output stream
 *
 * @str: string to be printed
 * @num: pointer to an int var that tracks number of strings to be printed
 *
 * Return: void
 */

void write_string(const char *str, int *num)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (num != NULL)
		{
			write_char(str[i], num);
		}
	}
}


/**
 * _printf - function produces output according to a format
 *
 * @format: type of format in arg
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, num = 0;

	va_list args;

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				char c = va_arg(args, int);

				write_char(c, &num);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				char *s = va_arg(args, char *);

				write_string(s, &num);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				write_char('%', &num);
				i++;
			}
		}
		else
		{
			write_char(format[i], &num);
		}
	}
	va_end(args);
	return (num);
}
