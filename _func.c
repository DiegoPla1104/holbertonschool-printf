#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * _itoa - Convert int to string.
 * @n: integer.
 * @a: array.
 *
 * Return: String.
 */

char *_itoa(long int n, char a[])
{
	int i = 0, flag = 0, piv, st;
	char aux, *p;

	if (n == 0)
	{
		a[i++] = '0';
		a[i] = '\0';
	}

	if (n < 0)
	{
		n = -n;
		flag = 1;
	}

	while (n != 0)
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
