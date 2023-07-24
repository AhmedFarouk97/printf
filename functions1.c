#include "main.h"

/**
 * print_c - prints a char
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 * @flags:  Calculates active flags
 *
 * Return: the number of characters printed
 */
int print_c(va_list args, char *buffer, int flags)
{
	char c = va_arg(args, int);
	int i = 0;

	(void)flags;
	buffer[i] = c;

	return (write(1, &buffer[0], 1));
}

/**
 * print_s - prints a string
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 * @flags:  Calculates active flags
 *
 * Return: the number of characters printed
 */
int print_s(va_list args, char *buffer, int flags)
{
	char *s = va_arg(args, char*);
	int len = 0, i;

	(void)buffer;
	(void)flags;

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		write(1, &s[i], 1);
		len++;
	}
	return (len);
}
/**
 * print_5 - print percent
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 * @flags:  Calculates active flags
 *
 * Return: the number of characters printed
 */
int print_5(va_list args, char *buffer, int flags)
{
	(void)args;
	(void)buffer;
	(void)flags;

	return (write(1, "%", 1));
}
/**
 * print_d - Prints a number
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags
 *
 * Return: Number of printed chars
 */
int print_d(va_list args, char *buffer, int flags)
{
	int long n = va_arg(args, int);
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	if (n < 0)
	{
		n = -1 * n;
		is_negative = 1;
	}

	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;
	return (write_num(i, is_negative, buffer, flags));
}
/**
 * print_b - Prints an unsigned number
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 *
 * Return: Numbers of char printed.
 */
int print_b(va_list args, char *buffer, int flags)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int len;

	(void)buffer;
	(void)flags;

	n = va_arg(args, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, len = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			len++;
		}
	}
	return (len);
}
