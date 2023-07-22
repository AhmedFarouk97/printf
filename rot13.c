#include "main.h"
#include <stddef.h>
/**
 * print_rot13 - prints a rot13'ed string
 * @args: variable arguments corresponding to format specifiers
 *
 * Return: number of characters printed
 */
int print_rot13(va_list args)
{
	char *str = va_arg(args, char *);
	int i, count = 0;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'm') || (str[i] >= 'A' && str[i] <= 'M'))
			count += _putchar(str[i] + 13);
		else if ((str[i] >= 'n' && str[i] <= 'z') ||
				(str[i] >= 'N' && str[i] <= 'Z'))
			count += _putchar(str[i] - 13);
		else
			count += _putchar(str[i]);
	}

	return (count);
}
