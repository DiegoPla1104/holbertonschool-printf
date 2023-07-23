#include "main.h"
#include <string.h>
#include <unistd.h>
/**
 * print_S - Prints a string.
 * @ap: va_list.
 *
 * Return: Numbers of characters to printed.
 */

int print_S(va_list ap)
{
	char *str = va_arg(ap, char *), buff[50];
	char hex[] = "0123456789ABCDEF";
	int i = 0, a = 0;

	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			buff[a++] = '\\';
			buff[a++] = 'x';

			/**
			 * (str[i] >> 4) shift the bits of the character to the right
			 * 4 positions, this is equivalent to dividing the character
			 * by 16. The result is the hexadecimal digit.
			 * & 0xF We are using it to keep only the 4 least significant
			 * bits of the result (binary), so we make sure that the value
			 * is between 0 and 15.
			 */

			buff[a++] = hex[(str[i] >> 4) & 0xF];
			buff[a++] = hex[(str[i]) & 0xF];
		}
		else
			buff[a++] = str[i];
		i++;
	}
	write(1, buff, a);
	return (a);
}
