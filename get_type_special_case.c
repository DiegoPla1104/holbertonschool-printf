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

int (*get_type(char f))(va_list ap)
{
	ty_f type[] = {
			{'c', print_char},
			{'s', print_str},
			{'d', print_num},
			{'i', print_num},
			{'%', print_per},
			{0, per_ch}
		};
		int j = 0;

		while (j < 6)
		{
			if (type[j].ty == f || type[j].ty == 0)
			{
				break;
			}
			j++;
		}

		return (type[j].fn);
}

/**
 * special_case - Chek and prints.
 * @f: Pointer.
 *
 * Return: (0) Success.
 */

int special_case(char f)
{
	if (f == '\\')
		_putchar('\\');
	else if (f == '\"')
		_putchar('\"');
	else if (f == '\'')
		_putchar('\'');
	else if (f == '%')
		_putchar('%');
	else if (f == 'n')
		_putchar('\n');

	return (1);
}
