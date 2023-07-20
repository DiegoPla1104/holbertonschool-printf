#include "main.h"

/**
 * count_chars - Count chars who prints.
 * @f: Pointer.
 *
 * Return: Num of chars.
 */

int count_chars(const char *f)
{
	int c = 0, i = 0;

	do {
		if (f[i] == '\\')
			c += 1;

		else if (f[i] == '%' && f[i + 1] != '\0')
			i += 2;

		else if (f[i] == '%')
			i++;

		else
		{
			c += 1;
			i++;
		}
	} while (f[i] != '\0');

	return (c);
}
