#include "main.h"
#include <stddef.h>
/**
 * print_char - print a single character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}
/**
 * print_string - prints a string
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}
	return (count);
}
/**
 * print_percent - print a percent sign
 * @args: unused
 *
 * Return: number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
/**
 * print_integer - Prints a signed integer in decimal format
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	char buffer[20];
	int i = 0, count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

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
