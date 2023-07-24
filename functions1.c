#include "main.h"

/**
 * print_c - prints a char
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 *
 * Return: the number of characters printed
 */
int print_c(va_list args, char *buffer)
{
	char c = va_arg(args, int);
	int i = 0;

	buffer[i] = c;

	return (write(1, &buffer[0], 1));
}

/**
 * print_s - prints a string
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 *
 * Return: the number of characters printed
 */
int print_s(va_list args, char *buffer)
{
	char *s = va_arg(args, char*);
	int len = 0, i;

	(void)buffer;

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
 * print_p - print percent
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 *
 * Return: the number of characters printed
 */
int print_p(va_list args, char *buffer)
{
	(void)args;
	(void)buffer;

	return (write(1, "%", 1));
}
/**
 * print_d - Prints a number
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * Return: Number of printed chars
 */
int print_d(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	int num = va_arg(args, int);
	int len = 0;
	int is_negative = 0;

	if (num == 0)
	{
		buffer[i--] = '0';
		len++;
	}
	else
	{
		if (num < 0)
		{
			is_negative = 1;
			if (num == INT_MIN)
			{
				buffer[i--] = '8';
				num = -(num / 10);
				len++;
			}
			else
				num = -num;
		}
		buffer[BUFFER_SIZE - 1] = '\0';
		while (num > 0)
		{
			buffer[i--] = (num % 10) + '0';
			num /= 10;
			len++;
		}
		if (is_negative)
		{
			buffer[i--] = '-';
			len++;
		}
	}
	i++;
	return (write(1, &buffer[i], len));
}
/**
 * print_b - Prints an unsigned number
 * @args: Lista of arguments
 * @buffer: Buffer array to handle print
 *
 * Return: Numbers of char printed.
 */
int print_b(va_list args, char *buffer)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int len;

	(void)buffer;

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
