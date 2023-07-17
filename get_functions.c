#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_char - Print char.
 * @ap: va_list.
 * @c: integer.
 *
 * Return: (0).
 */

int print_char(va_list ap, int c)
{
	_putchar(va_arg(ap, int));

	c += 1;
	return (0);
}

/**
 * print_str - Print Strings.
 * @ap: va_list.
 * @c: integer.
 *
 * Return: Nothing.
 */

int print_str(va_list ap, int c)
{
	char *p;

	p = va_arg(ap, char *);

	if (p == NULL)
	{
		write(1, "(nil)", 5);
		c = c + 5;
		return (0);
	}

	write(1, p, strlen(p));

	c = c + strlen(p);
	return (0);
}

/**
 * print_num - Print number.
 * @ap: va_list.
 * @c: integer.
 *
 * Return: Nothing.
 */

int print_num(va_list ap, int c)
{
	char arr[15], *p;

	p = _itoa(va_arg(ap, unsigned int), arr);

	write(1, p, strlen(p));

	c = c + strlen(p);

	return (0);
}
