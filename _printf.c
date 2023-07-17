#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * _printf - Prints har, tring and integer.
 * @format: Pointer.
 *
 * Return: Number of chars it prints.
 */

int _printf(const char *format, ...)
{
	int i, num_char = 0;
	va_list ap;

	if (format == NULL)
		return (0);

	num_char = count_chars(format);

	va_start(ap, format);

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			get_type(format[i])(ap, num_char);
		}
		else if (format[i] == '\\')
		{
			format++;
			i++;
			special_case(format);
		}
		else
			_putchar(format[i]);

		i++;
	}

	va_end(ap);

	return (num_char);
}
