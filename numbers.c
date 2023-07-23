#include "main.h"
/**
 * num_len - gets the length of an integer
 * @num: the integer
 *
 * Return: the length of the integer
 */
int num_len(int num)
{
	int len = 0;

	while (num > 0)
	{
		num /= 10;
		len++;
	}

	return (len);
}

/**
 * print_number - prints an integer
 * @num: the integer
 */
void print_number(int num)
{
	if (num == 0)
		return;

	print_number(num / 10);
	_putchar(num % 10 + '0');
}
/**
 * print_d - prints an integer
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int print_d(va_list args)
{
	int num = va_arg(args, int);
	int len = 0, negative = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	if (num < 0)
	{
		negative = 1;
		len++;
		if (num == INT_MIN)
		{
			_putchar('-');
			return (11);
		}
		num = -num;
	}

	len += num_len(num);
	if (negative)
		_putchar('-');

	print_number(num);

	return (len);
}
