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
 * print_integer - prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	if (num / 10)
		count += print_integer_helper(num / 10);
	_putchar(num % 10 + '0');
	count++;
	return (count);
}
/**
 * print_integer_helper - helper function for print_integer
 * @num: integer to print
 *
 * Return: number of digits printed
 */
int print_integer_helper(int num)
{
	int count = 0;

	if (num / 10)
		count += print_integer_helper(num / 10);
	_putchar(num % 10 + '0');
	count++;
	return (count);
}
