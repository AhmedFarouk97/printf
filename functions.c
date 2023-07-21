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
