#include "main.h"

/**
 * print_c - prints a char
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_c(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}

/**
 * print_s - prints a string
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_s(va_list args)
{
	char *s = va_arg(args, char*);
	int len = 0;

	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}

/**
 * print_p - prints a percent sign
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_p(va_list args)
{
	(void)args;

	write(1, "%", 1);
	return (1);
}

/**
 * print_d - function that prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	char buffer[20];
	int i = 0, count = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}

	return (count);
}
