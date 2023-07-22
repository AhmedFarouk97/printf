#include "main.h"
/**
 * print_unsigned - Prints an unsigned integer
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}
/**
 * print_octal - Prints an unsigned int in octal
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 8) + '0';
		num = num / 8;
	}

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}

/**
 * print_hex - Prints an unsigned int in lowercase hexadecimal
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_hex(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			buffer[i++] = remainder + '0';
		else
			buffer[i++] = remainder - 10 + 'a';
		num = num / 16;
	}

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}

/**
 * print_HEX - Prints an unsigned int in uppercase hexadecimal
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_HEX(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[20];
	int i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		int remainder = num % 16;

		if (remainder < 10)
			buffer[i++] = remainder + '0';
		else
			buffer[i++] = remainder - 10 + 'A';
		num = num / 16;
	}

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}
