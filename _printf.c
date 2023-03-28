#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

/**
 * _printf - function produces output according to a format
 *
 * @format: pointer to string type of format in arg
 * Return: number of characters printed (excluding the null byte)
 */

int _printf(const char *format, ...)
{
	int i, j, len = 0;

	va_list args;

	/* printers array of type printer_t containing format specifiers */
	printer_t printers[] = {{"s", print_string}, {"c", print_char}, {"d", print_int}, {"i", print_int}, {NULL, NULL}};

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]), len++;
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%'), len++, i++;
		}
		else
		{
			for (j = 0; printers[j].type != NULL; j++)
			{
				if (format[i + 1] == *(printers[j].type))
				{
					len += printers[j].print(args);
					i++;
					break;
				}
			}
			if (printers[j].type == NULL)
			{
				_putchar(format[i]), len++;
			}
		}
	}
	va_end(args);
	return (len);
}
