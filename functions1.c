#include "main.h"

/**
 * print_c - prints a char
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 * @buffer_size: size of the buffer
 *
 * Return: the number of characters printed
 */
int print_c(va_list args, char *buffer, int buffer_size)
{
	char c = va_arg(args, int);

	if (buffer_size < 1)
		return (-1);

	*buffer = c;
	return (1);
}

/**
 * print_s - prints a string
 * @args: the argument list
 * @buffer: pointer to the buffer to print to
 * @buffer_size: size of the buffer
 *
 * Return: the number of characters printed
 */
int print_s(va_list args, char *buffer, int buffer_size)
{
	char *s = va_arg(args, char*);
	int len = 0;

	if (s == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		if (len >= buffer_size)
			return (-1);
		buffer[len] = *s;
		s++;
		len++;
	}
	return (len);
}
/**
 * print_d - prints a decimal (int) number
 * @args: the argument list
 * @buffer: output buffer
 * @buffer_size: size of the output buffer
 *
 * Return: the number of characters printed
 */
int print_d(va_list args, char *buffer, int buffer_size)
{
	int num = va_arg(args, int);
	int len = 0, i;
	int is_negative = 0;
	unsigned int n;

	if (num < 0)
	{
		is_negative = 1;
		if (num == INT_MIN)
			n = (unsigned int)INT_MAX + 1;
		else
			n = (unsigned int)(-num);
	}
	else
		n = (unsigned int)num;

	do {
		if (len < buffer_size - 1)
			buffer[len] = (n % 10) + '0';
		len++;
		n /= 10;
	} while (n > 0);

	if (is_negative)
	{
		if (len < buffer_size - 1)
			buffer[len] = '-';
		len++;
	}

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	return (len);
}
