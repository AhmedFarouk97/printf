#include "main.h"
#include "main.h"
/**
 * print_b - prints an unsigned int in binary format
 * @args: the argument list
 * @buffer: buffer to store the printed string
 * @buffer_size: maximum size of the buffer
 *
 * Return: the number of characters printed
 */
int print_b(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;

	do {
		if (len + 1 >= buffer_size)
			return (-1); /* Not enough space in buffer */
		buffer[len++] = (num % 2) + '0';
		num /= 2;
	} while (num > 0);

	buffer[len] = '\0';

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	return (len);
}
/**
 * print_u - prints an unsigned int in decimal format
 * @args: the argument list
 * @buffer: the buffer to store the output
 * @buffer_size: the size of the buffer
 *
 * Return: the number of characters printed
 */
int print_u(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;

	do {
		if (len < buffer_size - 1)
			buffer[len] = (num % 10) + '0';
		len++;
		num /= 10;
	} while (num > 0);

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	if (len < buffer_size)
		buffer[len] = '\0';

	return (len);
}
/**
 * print_o - prints an unsigned int in octal format
 * @args: the argument list
 * @buffer: the buffer to store the output
 * @buffer_size: the size of the buffer
 *
 * Return: the number of characters printed
 */
int print_o(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;

	if (buffer_size <= 0)
		return (-1);

	do {
		if (len + 1 >= buffer_size)
			break;
		buffer[len++] = (num % 8) + '0';
		num /= 8;
	} while (num > 0);

	if (len == buffer_size)
		len--;

	buffer[len] = '\0';

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	return (len);
}

/**
 * print_x - prints an unsigned int in lowercase hexadecimal format
 * @args: the argument list
 * @buffer: the buffer to write to
 * @buffer_size: the size of the buffer
 *
 * Return: the number of characters printed
 */
int print_x(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	int remainder;
	char temp;

	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else
			buffer[len++] = remainder - 10 + 'a';
		num /= 16;
	} while (num > 0);
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}
	if (len < buffer_size)
	{
		for (i = 0; i < len; i++)
		{
			buffer[i] = buffer[i];
		}
		buffer[len] = '\0';
	}
	else
		return (-1);

	return (len);
}
/**
 * print_X - prints an unsigned int in lowercase hexadecimal format
 * @args: the argument list
 * @buffer: the buffer to write to
 * @buffer_size: the size of the buffer
 *
 * Return: the number of characters printed
 */
int print_X(va_list args, char *buffer, int buffer_size)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	int remainder;
	char temp;

	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else
			buffer[len++] = remainder - 10 + 'A';
		num /= 16;
	} while (num > 0);
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}
	if (len < buffer_size)
	{
		for (i = 0; i < len; i++)
		{
			buffer[i] = buffer[i];
		}
		buffer[len] = '\0';
	}
	else
		return (-1);

	return (len);
}
