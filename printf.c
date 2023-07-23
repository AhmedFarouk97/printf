#include "main.h"

/**
 * handle_specifier - handles a single specifier
 * @format: pointer to the format string
 * @args: va_list of arguments to print
 * @specifiers: array of specifiers to check against
 * @buffer: the output buffer
 * @buffer_index: the current index in the buffer
 *
 * Return: the number of characters printed
 */
int handle_specifier(const char *format, va_list args, spec_t *specifiers,
		     char *buffer, int *buffer_index)
{
	int j, printed_chars, len = 0;

	for (j = 0; specifiers[j].spec; j++)
	{
		if (format[1] == *specifiers[j].spec)
		{
			printed_chars = specifiers[j].f(args, buffer + *buffer_index,
							BUFFER_SIZE - *buffer_index);
			if (printed_chars < 0)
				return (-1);
			len += printed_chars;
			*buffer_index += printed_chars;
			break;
		}
	}
	if (!specifiers[j].spec && format[1] != '\0')
	{
		if (*buffer_index >= BUFFER_SIZE)
		{
			write(1, buffer, *buffer_index);
			*buffer_index = 0;
		}
		buffer[(*buffer_index)++] = format[0];
		if (format[1] == '%')
			format++;
		len++;
	}

	return (len);
}

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
	int i, len = 0;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;

	if (format == NULL)
		return (-1);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0' || format[i + 1] == ' ')
				return (-1);
			len += handle_specifier(format + i, args, specifiers,
							buffer, &buffer_index);
			i++;
		}
		else
		{
			if (buffer_index >= BUFFER_SIZE)
			{
				write(1, buffer, buffer_index);
				buffer_index = 0;
			}
			buffer[buffer_index++] = format[i];
			len++;
		}
	}
	if (buffer_index > 0)
		write(1, buffer, buffer_index);

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
		{"p", print_p},
		{"d", print_d},
		{"i", print_d},
		{"b", print_b},
		{"u", print_u},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{NULL, NULL}
	};

	va_start(args, format);
	len = loop_format_string(format, args, specifiers);
	va_end(args);

	return (len);
}
