#include "main.h"
#include <unistd.h>
/**
 * handle_specifier - handles a single format specifier
 * @format: string containing format specifier
 * @args: variable arguments corresponding to format specifier
 * @buffer: buffer array to store the output
 * @buff_ind: pointer to the buffer index
 *
 * Return: number of characters printed
 */
int handle_specifier(const char *format, va_list args,
		char buffer[], int *buff_ind)
{
	int j, count = 0;

	specifier_t list[] = {
		{"s", print_string}, {"c", print_char}, {"%", print_percent},
		{"d", print_integer}, {"i", print_integer}, {"b", binary},
		{"u", print_unsigned}, {"o", print_octal}, {"x", print_hex},
		{"X", print_HEX}, {"S", print_S}, {"p", print_pointer},
		{"R", print_rot13}, {NULL, NULL}
	};

	for (j = 0; list[j].valid_types; j++)
	{
		if (format[1] == *(list[j].valid_types))
		{
			print_output(buffer, buff_ind, count);
			count += list[j].f(args);
			break;
		}
	}
	if (!list[j].valid_types)
	{
		print_output(buffer, buff_ind, count);
		write(1, "%", 1);
		write(1, &format[1], 1);
		count += 2;
	}

	return (count);
}

/**
 * handle_specifiers - handles the format specifiers
 * using the handle_specifier function
 * @format: string containing format specifiers
 * @args: variable arguments corresponding to format specifiers
 * @buffer: buffer array to store the output
 * @buff_ind: pointer to the buffer index
 *
 * Return: number of characters printed
 */
int handle_specifiers(const char *format, va_list args,
		char buffer[], int *buff_ind)
{
	int i, count = 0;

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			count += handle_specifier(&format[i], args, buffer, buff_ind);
			i++;
		}
		else
		{
			if (*buff_ind == BUFFER_SIZE)
				print_output(buffer, buff_ind, count);
			buffer[*buff_ind] = format[i];
			(*buff_ind)++;
			count++;
		}
	}

	return (count);
}
/**
 * print_output - prints the contents of the buffer if it exists
 * @buffer: buffer array to store the output
 * @buff_ind: pointer to the buffer index
 * @count: number of characters printed
 */
void print_output(char buffer[], int *buff_ind, int count)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
		count += *buff_ind;
		*buff_ind = 0;
	}
}

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
	int count = 0, buffer_index = 0;
	char buffer[BUFFER_SIZE];

	va_start(args, format);
	count = handle_specifiers(format, args, buffer, &buffer_index);
	print_output(buffer, &buffer_index, count);
	va_end(args);

	return (count);
}
