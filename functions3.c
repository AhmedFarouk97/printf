#include "main.h"
/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hex - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii: ASSCI CODE.
 *
 * Return: Always 3
 */
int add_hex(char ascii, char *buffer, int i)
{
	char map[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map[ascii / 16];
	buffer[i] = map[ascii % 16];

	return (3);
}
/**
 * print_S - prints a string
 * @args: the argument list
 * @flags: get flags
 * @size: get size
 *
 * Return: the number of characters printed
 */
int print_S(va_list args, int flags, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);
	char buffer[BUFFER_SIZE];

	(void)flags;
	(void)size;
	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += add_hex(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
/**
 * print_p - Prints the value of a pointer variable
 * @args: List a of arguments
 * @flags: get flags
 * @size: get size
 *
 * Return: Number of chars printed.
 */
int print_p(va_list args, int flags, int size)
{
	void *addrs = va_arg(args, void *);
	unsigned long n;
	char map[] = "0123456789abcdef";
	char buffer[BUFFER_SIZE];
	int i = 0, j = 0, len, temp;

	(void)flags;
	(void)size;
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	n = (unsigned long)addrs;
	while (n > 0)
	{
		buffer[i] = map[n % 16];
		n /= 16;
		i++;
	}
	buffer[i++] = 'x';
	buffer[i++] = '0';
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
