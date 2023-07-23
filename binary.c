#include "main.h"
/**
 * print_b - prints an unsigned int in binary format
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_b(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int len = 0, i;
	char buffer[1024];

	do {
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

	write(1, buffer, len);
	return (len);
}
