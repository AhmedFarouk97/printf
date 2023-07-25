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
 * @buffer: pointer to the buffer to print to
 * @flags: add flags
 * @size: get size
 * @precision: get percision
 * @width: gets width
 *
 * Return: the number of characters printed
 */
int print_S(va_list args, char *buffer, int flags, int size,
		int precision, int width)
{
	int i = 0, offset = 0;
	char *str = va_arg(args, char *);

	(void)buffer;
	(void)flags;
	(void)size;
	(void)precision;
	(void)width;

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
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @size: get size
 * @precision: get percision
 * @width: gets width
 *
 * Return: Number of chars printed.
 */
int print_p(va_list args, char *buffer, int flags, int size,
		int precision, int width)
{
	int ind = BUFFER_SIZE - 2;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(args, void *);
	int len;

	(void)flags;
	(void)size;
	(void)precision;
	(void)width;

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
	}
	buffer[ind--] = 'x';
	buffer[ind--] = '0';

	ind++;
	len = BUFFER_SIZE - ind - 1;
	return (write(1, &buffer[ind], len));
}
