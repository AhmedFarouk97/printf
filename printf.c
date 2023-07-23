#include "main.h"
/**
 * loop_format_string - loops over the format string and handles the specifiers
 * @format: pointer to the format string
 * @args: va_list of arguments to print
 * @specifiers: array of specifiers to check against
 *
 * Return: the number of characters printed
 */
int loop_format_string(const char *format, va_list args, spec_t *specifiers)
{
	int i, j, len = 0;

	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0' || format[i + 1] == ' ')
				return (-1);
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

	return (len);
}
/**
 * _printf - prints a formatted string to stdout
 * @format: pointer to the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	spec_t specifiers[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_p},
		{"d", print_d},
		{"i", print_d},
		{"b", print_b},
		{NULL, NULL}
	};

	va_start(args, format);
	len = loop_format_string(format, args, specifiers);
	va_end(args);

	return (len);
}
