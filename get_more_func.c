#include "main.h"
#include <unistd.h>
#include <string.h>

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
	char buff[40], aux;

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
			buff[i++] = reminder + '0';
		}
		len = i;
		i -= 1;
		while (start < i)
		{
			aux = buff[start];
			buff[start++] = buff[i];
			buff[i--] = aux;
		}
		write(1, buff, len);
	}
	return (len);
}

/**
 * print_uint - Prints an unsigned decimal (base 10) number.
 * @ap: va_list.
 *
 * Return: Number of characters to printed.
 */

int print_uint(va_list ap)
{
	unsigned long int unsig_num = va_arg(ap, unsigned long int);
	int i, start, reminder = 0, len = 0;
	char buff[30], aux;

	if (unsig_num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (unsig_num > 0)
	{
		reminder = unsig_num % 10;
		buff[i++] = reminder + '0';
		unsig_num = unsig_num / 10;
	}
	start = 0;
	len = i;
	i = i - 1;
	while (start < i)
	{
		aux = buff[start];
		buff[start++] = buff[i];
		buff[i--] = aux;
	}
	write(1, buff, len);
	return (len);
}

/**
 * print_octal - Print a number in octal (base 8).
 * @ap: va_list.
 *
 * Return: Numbers of characteres to printed.
 */

int print_octal(va_list ap)
{
	long int octal_num = va_arg(ap, long int);
	int i, start, reminder = 0, flag = 0, len = 0;
	char buff[40], aux;

	if (octal_num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (octal_num < 0)
	{
		octal_num = -octal_num;
		flag = 1;
	}
	i = 0;
	while (octal_num > 0)
	{
		reminder = octal_num % 8;
		buff[i++] = reminder + '0';
		octal_num = octal_num / 8;
	}

	if (flag == 1)
		buff[i++] = '-';

	start = 0;
	len = i;
	i = i - 1;
	while (start < i)
	{
		aux = buff[start];
		buff[start++] = buff[i];
		buff[i--] = aux;
	}
	write(1, buff, (len));
	return (len);
}

/**
 * print_hex - Print a number in hxadecimal (base 16).
 * @ap: va_list.
 *
 * Return: Number of characters to printed.
 */

int print_hex(va_list ap)
{
	long int hex_num = va_arg(ap, long int);
	int i, start, flag = 0, len = 0, reminder = 0;
	char aux, buff[30];

	if (hex_num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (hex_num < 0)
	{
		hex_num = -hex_num;
		flag = 1;
	}
	i = 0;
	while (hex_num > 0)
	{
		reminder = hex_num % 16;
		if (reminder < 10)
			buff[i++] = reminder + '0';
		else
			buff[i++] = (reminder - 10) + 'a';
		hex_num = hex_num / 16;
	}
	if (flag == 1)
		buff[i++] = '-';
	start = 0;
	len = i;
	i = i - 1;
	while (start < i)
	{
		aux = buff[start];
		buff[start++] = buff[i];
		buff[i--] = aux;
	}
	write(1, buff, len);
	return (len);
}

/**
 * print_HEX - Print a number in hexadecimal (base 16) with (ABCDEF).
 * @ap: va_list.
 *
 * Return: Numbers of character to printed.
 */

int print_HEX(va_list ap)
{
	long int HEX_num = va_arg(ap, long int);
	int i, start, flag = 0, len = 0, reminder = 0;
	char aux, buff[30];

	if (HEX_num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (HEX_num < 0)
	{
		HEX_num = -HEX_num;
		flag = 1;
	}
	i = 0;
	while (HEX_num > 0)
	{
		reminder = HEX_num % 16;
		if (reminder < 10)
			buff[i++] = reminder + '0';
		else
			buff[i++] = (reminder - 10) + 'A';
		HEX_num = HEX_num / 16;
	}
	if (flag == 1)
		buff[i++] = '-';
	start = 0;
	len = i;
	i = i - 1;
	while (start < i)
	{
		aux = buff[start];
		buff[start++] = buff[i];
		buff[i--] = aux;
	}
	write(1, buff, len);
	return (len);
}
