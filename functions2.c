#include "main.h"
/**
 * print_u - prints an unsigned int in decimal format
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_u(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	char buffer[1024];
	char temp;

	do {
		buffer[len++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	buffer[len] = '\0';

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	write(1, buffer, len);
	return (len);
}

/**
 * print_o - prints an unsigned int in octal format
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_o(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	char buffer[1024];
	char temp;

	do {
		buffer[len++] = (num % 8) + '0';
		num /= 8;
	} while (num > 0);

	buffer[len] = '\0';

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	write(1, buffer, len);
	return (len);
}

/**
 * print_x - prints an unsigned int in lowercase hexadecimal format
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_x(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	int remainder;
	char buffer[1024];
	char temp;

	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else
			buffer[len++] = remainder - 10 + 'a';
		num /= 16;
	} while (num > 0);

	buffer[len] = '\0';

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	write(1, buffer, len);
	return (len);
}

/**
 * print_X - prints an unsigned int in uppercase hexadecimal format
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_X(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	int remainder;
	char buffer[1024];
	char temp;

	do {
		remainder = num % 16;
		if (remainder < 10)
			buffer[len++] = remainder + '0';
		else
			buffer[len++] = remainder - 10 + 'A';
		num /= 16;
	} while (num > 0);

	buffer[len] = '\0';

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	write(1, buffer, len);
	return (len);
}
