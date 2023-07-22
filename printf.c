#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - prints a formatted string to stdout
 * @format: pointer to the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, len = 0;

	spec_t specifiers[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_p},
		{"d", print_d},
		{"i", print_d},
		{NULL, NULL}
	};
	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; specifiers[j].spec; j++)
			{
				if (format[i + 1] == *specifiers[j].spec)
				{
					len += specifiers[j].f(args);
					i++;
					break;
				}
			}
			if (!specifiers[j].spec && format[i + 1] != '\0')
			{
				write(1, &format[i], 1);
				len++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}
