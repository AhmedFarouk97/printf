#include "main.h"
/**
 * print_u - Prints an unsigned number
 * @args: List of arguments
 * @flags: get flags
 *
 * Return: Number of printed chars
 */
int print_u(va_list args, int flags)
{
	int i = 0, len, temp, j = 0;
	unsigned long int n = va_arg(args, unsigned int);
	char buffer[BUFFER_SIZE];

	(void)flags;
	if (n == 0)
		buffer[i] = '0';
	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
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

/**
 * print_o - Prints octal
 * @args: List of arguments
 * @flags: get flags
 *
 * Return: Number of printed chars
 */
int print_o(va_list args, int flags)
{
	unsigned long int n = va_arg(args, unsigned int);
	unsigned long int num = n;
	char buffer[BUFFER_SIZE];
	int i = 0, j = 0, temp, len;

	if (n == 0)
		buffer[i++] = '0';
	while (n > 0)
	{
		buffer[i] = (n % 8) + '0';
		n /= 8;
		i++;
	}
	if (flags == HASH && num != 0)
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

/**
 * print_hex - prints an unsigned int in lowercase hexadecimal format
 * @flags: get flags
 * @n: passed number
 * @map: passed map
 * @str: passed string
 *
 * Return: the number of characters printed
 */
int print_hex(unsigned long int n, char *map, int flags, char *str)
{
	char buffer[BUFFER_SIZE];
	unsigned long int num = n;
	int i = 0, j = 0, temp, len;

	if (n == 0)
		buffer[i++] = '0';
	while (n > 0)
	{
		buffer[i] = map[n % 16];
		n /= 16;
		i++;
	}
	if (flags == HASH && num != 0)
	{
		buffer[i++] = str[1];
		buffer[i++] = str[0];
	}
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
/**
 * print_x - prints an unsigned int in lowercase hexadecimal format
 * @args: the argument list
 * @flags: get flags
 *
 * Return: the number of characters printed
 */
int print_x(va_list args, int flags)
{
	unsigned long int n = va_arg(args, unsigned int);
	char map[] = "0123456789abcdef";
	char *str = "0x";

	return (print_hex(n, map, flags, str));
}
/**
 * print_X - prints an unsigned int in uppercase hexadecimal format
 * @args: the argument list
 * @flags: get flags
 *
 * Return: the number of characters printed
 */
int print_X(va_list args, int flags)
{
	unsigned long int n = va_arg(args, unsigned int);
	char map[] = "0123456789ABCDEF";
	char *str = "0X";

	return (print_hex(n, map, flags, str));
}
