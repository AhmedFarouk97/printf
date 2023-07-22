#include "main.h"
#include <stddef.h>

/**
 * _printf - prints a formatted string to stdout
 * @format: string containing format specifiers
 * @...: variable arguments corresponding to format specifiers
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0, j;

	specifier_t list[] = {
		{"s", print_string}, {"c", print_char}, {"%", print_percent},
		{"d", print_integer}, {"i", print_integer}, {NULL, NULL}
	};

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (list[j].valid_types)
			{
				if (format[i + 1] == *(list[j].valid_types))
				{
					count += list[j].f(args);
					break;
				}
				j++;
			}
			if (!list[j].valid_types)
			{
				_putchar(format[i]);
				_putchar(format[i + 1]);
			}
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
