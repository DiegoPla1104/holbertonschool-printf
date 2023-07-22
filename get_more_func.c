#include "main.h"
#include <unistd.h>

/**
 * convert_bin - Convets numbers from decimal to binary.
 *@ap: va_list.
 *
 * Return: Number of characters to printed.
 */

int convert_bin(va_list ap)
{
	unsigned int unsig_num, reminder = 0, quotient = 0, len = 0;
	int i = 0, start = 0;
	char arr[40], aux;

	unsig_num = va_arg(ap, unsigned int);
	if (unsig_num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		while (unsig_num > 0)
		{
			reminder = unsig_num % 2;
			quotient = unsig_num / 2;
			unsig_num = quotient;
			arr[i++] = reminder + '0';
		}
		arr[i] = '\0';
		i -= 1;
		len = i + 1;
		while (start < i)
		{
			aux = arr[start];
			arr[start++] = arr[i];
			arr[i--] = aux;
		}
		write(1, arr, len);
	}
	return (len);
}
