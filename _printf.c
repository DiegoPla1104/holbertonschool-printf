#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * procedure - Function to iterate and print %c, %s, %d, and %i.
 * @format: const char *.
 * @ap: va_list.
 *
 * Return: Number of chars how printed.
 */

int procedure(const char *format, va_list ap)
{
	int i = 0, cnt = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);

		if (format[i] == '%')
		{
			cnt += get_type(format[i + 1])(ap);

			if (get_type(format[i + 1]) == per_ch)
			{
				write(1, &format[i + 1], 1);
				i++;
			}
			if (get_type(format[i + 1]) != per_ch)
				i++;
		}
		else if (format[i] == '\\')
			cnt += special_case(format[i + 1]);
		else
			write(1, &format[i], 1);
		i++;
	}

	return (cnt);
}

/**
 * _printf - Prints char, string and integer.
 * @format: Pointer.
 *
 * Return: Number of chars it prints.
 */

int _printf(const char *format, ...)
{
	int cnt = 0, c = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	if (strcmp(format, "") == 0)
		return (0);

	cnt = count_chars(format);

	va_start(ap, format);

	c = procedure(format, ap);

	va_end(ap);

	if (c == -1)
		return (-1);
	else
		return (cnt + c);
}
