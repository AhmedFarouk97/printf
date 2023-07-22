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
	char *str = va_arg(args, char*);
	int i = 0;

	if (*str && str[i + 1] == '\0' && str[i] == '%')
		return (-1);

	write(1, "%", 1);
	return (1);
}
