#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _itoa - Convert int to string.
 * @n: integer.
 * @a: array.
 *
 * Return: String.
 */

char *_itoa(unsigned int n, char a[])
{
	unsigned int zero = 0;
	int i = 0, flag = 0, piv, st;
	char aux, *p;

	if (n == 0)
	{
		a[i++] = '0';
		a[i] = '\0';
	}

	if (n < zero)
	{
		n = -n;
		flag = 1;
	}

	while (n != zero)
	{
		piv = n % 10;
		a[i++] = piv + '0';
		n = n / 10;
	}

	if (flag == 1)
		a[i++] = '-';

	a[i] = '\0';

	st = 0;
	i = i - 1;
	while (st < i)
	{
		aux = a[st];
		a[st] = a[i];
		a[i] = aux;
		st++;
		i--;
	}
	p = a;
	return (p);
}
