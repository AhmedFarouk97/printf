#include "main.h"
#include <stddef.h>

/**
 * print_S - prints a string and non-printable characters
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_S(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			if (*str < 16)
				count += _putchar('0');
			count += hex_print(*str);
		}
		else
		{
			_putchar(*str);
			count++;
		}
		str++;
	}
	return (count);
}

/**
 * hex_print - prints the hexadecimal representation of a character
 * @n: the character to print
 *
 * Return: number of characters printed
 */
int hex_print(unsigned int n)
{
	unsigned int num = n;
	unsigned int count = 1;
	char hex_digits[] = "0123456789ABCDEF";

	while (num / 16 > 0)
	{
		count++;
		num /= 16;
	}
	while (count > 0)
	{
		_putchar(hex_digits[(n >> (4 * (count - 1))) & 0xF]);
		count--;
	}
	return (count);
}
