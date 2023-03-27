#include <stdio.h>
#include <unistd.h>

/**
 * _putchar - function prints out a single character
 *
 * @c: character to be printed
 *
 * Return: On success 1
 * On error, -1 is returned, errno is set appropriately
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}
