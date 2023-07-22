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

	if (s == NULL)
		s = "(null)";
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
	(void) args;

	write(1, "%", 1);
	return (1);
}
/**
 * print_d - prints an integer
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	int len = 0, divisor = 1;

	if (num < 0)
	{
		len += _putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		len += _putchar('0');
		return (len);
	}
	while (num / divisor > 9)
		divisor *= 10;
	while (divisor != 0)
	{
		len += _putchar(num / divisor + '0');
		num %= divisor;
		divisor /= 10;
	}
	return (len);
}
