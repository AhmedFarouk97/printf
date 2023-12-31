#include "main.h"

/**
 * print_c - prints a char
 * @args: the argument list
 * @flags: get flags
 * @size: get flags
 *
 * Return: the number of characters printed
 */
int print_c(va_list args, int flags, int size)
{
	char c = va_arg(args, int);

	(void)size;
	(void)flags;
	return (write(1, &c, 1));
}

/**
 * print_s - prints a string
 * @args: the argument list
 * @flags: get flags
 * @size: get flags
 *
 * Return: the number of characters printed
 */
int print_s(va_list args, int flags, int size)
{
	char *s = va_arg(args, char*);
	int len;

	(void)flags;
	(void)size;
	if (s == NULL)
		s = "(null)";
	for (len = 0; s[len]; len++)
	;

	return (write(1, s, len));
}
/**
 * print_5 - print percent
 * @args: the argument list
 * @flags: get flags
 * @size: get flags
 *
 * Return: the number of characters printed
 */
int print_5(va_list args, int flags, int size)
{
	(void)args;
	(void)flags;
	(void)size;
	return (write(1, "%%", 1));
}
/**
 * print_d - Prints a number
 * @args: List of arguments
 * @flags: get flags
 * @size: get flags
 *
 * Return: Number of printed chars
 */
int print_d(va_list args, int flags, int size)
{
	int i = 0, len, temp, j = 0;
	long int n = va_arg(args, long int);
	int is_negative = 0;
	char buffer[BUFFER_SIZE];

	n = convert_int(n, size);
	if (n == 0)
		buffer[i++] = '0';
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	for (i = 0; n > 0; i++)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		buffer[i++] = '-';
	else if (flags == (PLUS | SPACE))
		buffer[i++] = '+';
	else if (flags == PLUS)
		buffer[i++] = '+';
	else if (flags == SPACE)
		buffer[i++] = ' ';
	len = i;
	for (; i > j + 1; i--, j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
	}
	return (write(1, buffer, len));
}
/**
 * print_b - Prints an unsigned number
 * @args: Lista of arguments
 * @flags: get flags
 * @size: get flags
 *
 * Return: Numbers of char printed.
 */
int print_b(va_list args, int flags, int size)
{
	unsigned int n = va_arg(args, int);
	char buffer[BUFFER_SIZE];
	int i = 0, j = 0, temp, len;

	(void)flags;
	(void)size;
	if (n == 0)
		buffer[i++] = '0';
	for (i = 0; n > 0; i++)
	{
		buffer[i] = (n % 2) + '0';
		n /= 2;
	}
	len = i;
	while (i > j + 1)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
		i--;
		j++;
	}
	buffer[len] = '\0';
	return (write(1, buffer, len));
}
