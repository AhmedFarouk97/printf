#include "main.h"

/**
 * print_c - prints a char
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_c(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
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
	char *s;
	int i, len = 0;

	s = va_arg(args, char *);
	for (i = 0; s[i]; i++)
		len++;
	if (s == NULL)
	{
		s = "(null)";
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
	else
	{
		for (i = 0; i < len; i++)
			_putchar(s[i]);
		return (len);
	}
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

	_putchar(37);
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
