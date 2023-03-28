#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int print_string(va_list args);
int print_char(va_list args);

/**
 * struct printer - struct for printer functions
 *
 * @type: the conversion specifier
 * @print: the function to print the argument
 */

typedef struct printer
{
	char *type;
	int (*print)(va_list);
} printer_t;

#endif /* MAIN_H */
