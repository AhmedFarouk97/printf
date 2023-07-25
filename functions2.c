#include "main.h"
/**
 * print_u - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags
 *
 * Return: Number of printed chars
 */
int print_u(va_list args, char *buffer, int flags)
{
	int i = BUFFER_SIZE - 2;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int len = 0;

	(void)flags;
	if (num == 0)
	{
		buffer[i--] = '0';
		len++;
	}
	else
	{
		buffer[BUFFER_SIZE - 1] = '\0';

		while (num > 0)
		{
			buffer[i--] = (num % 10) + '0';
			num /= 10;
			len++;
		}
	}

	i++;

	return ((unsigned int)write(1, &buffer[i], len));
}
/**
 * print_o - Prints octal
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags
 *
 * Return: Number of printed chars
 */
int print_o(va_list args, char *buffer, int flags)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int init_num = num;
	int len;

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
 *
 * Return: the number of characters printed
 */
int print_x(va_list args, char *buffer, int flags)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int init_num = num;
	char map[] = "0123456789abcdef";
	int len;

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
 *
 * Return: the number of characters printed
 */
int print_X(va_list args, char *buffer, int flags)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned int);
	unsigned long int init_num = num;
	char map[] = "0123456789ABCDEF";
	int len;

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
