#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * get_type - Select the type, prints the string and counts chars.
 * @f: Pointer.
 *
 * Return: (0) Success.
 */

int (*get_type(char f))(va_list ap, int c)
{
	ty_f type[] = {
			{'c', print_char},
			{'s', print_str},
			{'d', print_num},
			{'i', print_num}
		};
		int j;

		j = 0;
		if (j == 0)
		{
			while (j < 4)
			{
				if (type[j].ty == f)
				{
					break;
				}
				j++;
			}

			return (type[j].fn);
		}

		if (f == '%')
			_putchar('%');

	return (0);
}

/**
 * special_case - Chek and prints.
 * @f: Pointer.
 *
 * Return: (0) Success.
 */

int special_case(const char *f)
{
	if (strcmp(f, "\\") == 0)
		_putchar('\\');
	else if (strcmp(f, "\"") == 0)
		_putchar('\"');
	else if (strcmp(f, "\'") == 0)
		_putchar('\'');
	else if (strcmp(f, "%") == 0)
		_putchar('%');
	else if (strcmp(f, "n") == 0)
		_putchar('\n');

	return (0);
}
