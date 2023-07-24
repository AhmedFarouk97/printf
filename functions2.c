#include "main.h"
/**
 * print_u - Prints an unsigned number
 * @args: List of arguments
 * @buffer: Buffer array to handle print.
 * Return: Number of printed chars
 */
int print_u(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int len = 0;

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
 *
 * Return: Number of printed chars
 */
int print_o(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int len = 0;

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
			buffer[i--] = (num % 8) + '0';
			num /= 8;
			len++;
		}
	}

	i++;

	return ((unsigned int)write(1, &buffer[i], len));
}
/**
 * print_x - prints an unsigned int in lowercase hexadecimal format
 * @args: the argument list
 * @buffer: the buffer to write to
 *
 * Return: the number of characters printed
 */
int print_x(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int len = 0;

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
			int remainder = num % 16;

			if (remainder < 10)
			{
				buffer[i--] = remainder + '0';
			}
			else
			{
				buffer[i--] = remainder - 10 + 'a';
			}
			num /= 16;
			len++;
		}
	}

	i++;

	return ((unsigned int)write(1, &buffer[i], len));
}

/**
 * print_X - prints an unsigned int in uppercase hexadecimal format
 * @args: the argument list
 * @buffer: the buffer to write to
 *
 * Return: the number of characters printed
 */
int print_X(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int len = 0;

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
			int remainder = num % 16;

			if (remainder < 10)
			{
				buffer[i--] = remainder + '0';
			}
			else
			{
				buffer[i--] = remainder - 10 + 'A';
			}
			num /= 16;
			len++;
		}
	}

	i++;

	return ((unsigned int)write(1, &buffer[i], len));
}
