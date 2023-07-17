#include "main.h"

/**
 * count_chars - Count chars who prints.
 * @f: Pointer.
 *
 * Return: Num of chars.
 */

int count_chars(const char *f)
{
	int c = 0;

	while (*f != '\0')
	{
		if (*f == '\\')
		{
			f++;
		}

		if (*f == '\"')
		{
			f++;
		}

		if (*f == '%')
		{
			f++;
			if (*f == '%')
			{
				c += 1;
			}
			else
				f++;
		}
		else
		{
			f++;
			c += 1;
		}
	}

	return (c);
}
