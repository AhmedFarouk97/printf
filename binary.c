#include "main.h"
/**
 * print_binary - Prints an unsigned int in binary
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0, count = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 2) + '0';
		num = num / 2;
	}

	while (i > 0)
	{
		_putchar(buffer[--i]);
		count++;
	}

	return (count);
}
