#include "main.h"
/**
 * print_d - prints a decimal (int) number
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	int len = 0, i;
	int is_negative = 0;
	char buffer[1024];
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
		buffer[len++] = (n % 10) + '0';
		n /= 10;
	} while (n > 0);

	if (is_negative)
		buffer[len++] = '-';

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
