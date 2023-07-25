#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
/**
 * handle_spec - Prints an argument based on its type
 * @format: Formatted string in which to print the arguments.
 * @args: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags:  Calculates active flags
 * @size: get size
 * @precision: get precisoin
 * @width: gets width
 *
 * Return: 1 or 2;
 */
int handle_spec(const char *format, int *ind, va_list args, char *buffer,
		int flags, int size, int precision, int width)
{
	int i, unknow_len = 0, printed_chars = -1;
	spec_t specifiers[] = {
		{'c', print_c}, {'s', print_s}, {'%', print_5},
		{'d', print_d}, {'i', print_d}, {'b', print_b},
		{'u', print_u}, {'o', print_o}, {'x', print_x},
		{'X', print_X}, {'S', print_S}, {'p', print_p},
		{'\0', NULL}
	};
	for (i = 0; specifiers[i].spec; i++)
		if (format[*ind] == specifiers[i].spec)
			return (specifiers[i].f(args, buffer, flags,
						size, precision, width));
	if (specifiers[i].spec == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			*ind -= 1;
			while (format[*ind] != ' ' && format[*ind] != '%')
				*ind -= 1;
			if (format[*ind] == ' ')
				*ind -= 1;
			return (1);
		}
		unknow_len += write(1, &format[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}


/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed_char = 0, len = 0;
	int flags, size, precision, width;
	int buff_ind = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			size = get_size(format, &i);
			precision = get_precision(format, &i, args);
			width = get_width(format, &i, args);
			++i;
			printed_char = handle_spec(format, &i, args, buffer, flags,
					size, precision, width);
			if (printed_char == -1)
				return (-1);
			len += printed_char;
		}
		else
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFFER_SIZE)
				print_buffer(buffer, &buff_ind);
			len++;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (len);
}
