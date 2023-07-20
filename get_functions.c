#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_char - Print char.
 * @ap: va_list.
 *
 * Return: Nothing.
 */

int print_char(va_list ap)
{
	char ch = va_arg(ap, int);

	write(1, &ch, 1);
	return (1);
}

/**
 * print_str - Print Strings.
 * @ap: va_list.
 *
 * Return: Nothing.
 */

int print_str(va_list ap)
{
	char *p;

	p = va_arg(ap, char *);

	if (p == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		write(1, p, strlen(p));

	return (strlen(p));
}

/**
 * print_num - Print number.
 * @ap: va_list.
 *
 * Return: Nothing.
 */

int print_num(va_list ap)
{
	int count = 0;
	char arr[15], *p;

	p = _itoa(va_arg(ap, int), arr);

	write(1, p, strlen(p));

	count = strlen(p);
	return (count);
}

/**
 * print_per - Prints %.
 * @ap: Va_list.
 *
 * Return: Nothing.
 */

int print_per(va_list ap)
{
	(void) ap;

	write(1, "%", 1);
	return (1);
}

/**
 * per_ch - Prints %.
 * @ap: va_list.
 *
 * Return: Number of char.
 */

int per_ch(va_list ap)
{
	(void) ap;

	write(1, "%", 1);
	return (2);
}
