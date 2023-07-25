#include "main.h"
/**
 * print_u - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags
 * @size: gets size
 * @precision: gets percision
 * @width: gets width
 *
 * Return: Number of printed chars
 */
int print_u(va_list args, char *buffer, int flags, int size,
		int precision, int width)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	int len;

	(void)flags;
	(void)precision;
	(void)width;
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	len = BUFFER_SIZE - i - 1;
	return (write(1, &buffer[i], len));
}

/**
 * print_o - Prints octal
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags
 * @size: gets size
 * @precision: gets percision
 * @width: gets width
 *
 * Return: Number of printed chars
 */
int print_o(va_list args, char *buffer, int flags, int size,
		int precision, int width)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int init_num = num;
	int len;

	(void)precision;
	(void)width;
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	len = BUFFER_SIZE - i - 1;
	return (write(1, &buffer[i], len));
}
/**
 * print_x - prints an unsigned int in lowercase hexadecimal format
 * @args: the argument list
 * @buffer: the buffer to write to
 * @flags:  Calculates active flags
 * @size: gets size
 * @precision: gets percision
 * @width: gets width
 *
 * Return: the number of characters printed
 */
int print_x(va_list args, char *buffer, int flags, int size,
		int precision, int width)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int init_num = num;
	char map[] = "0123456789abcdef";
	int len;

	(void)precision;
	(void)width;
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = 'x';
		buffer[i--] = '0';
	}
	i++;
	len = BUFFER_SIZE - i - 1;
	return (write(1, &buffer[i], len));
}

/**
 * print_X - prints an unsigned int in uppercase hexadecimal format
 * @args: the argument list
 * @buffer: the buffer to write to
 * @flags:  Calculates active flags
 * @size: gets size
 * @precision: gets percision
 * @width: gets width
 *
 * Return: the number of characters printed
 */
int print_X(va_list args, char *buffer, int flags, int size,
		int precision, int width)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int init_num = num;
	char map[] = "0123456789ABCDEF";
	int len;

	(void)precision;
	(void)width;
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = 'X';
		buffer[i--] = '0';
	}
	i++;
	len = BUFFER_SIZE - i - 1;
	return (write(1, &buffer[i], len));
}
