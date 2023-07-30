#include "main.h"
/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @ind: take a parameter.
 *
 * Return: Flags:
 */
int get_flags(const char *format, int *ind)
{
	int j, i;
	int flags = 0;
	const char FLAGS_CH[] = {'+', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {PLUS, HASH, SPACE, 0};

	for (i = *ind + 1; format[i]; i++)
	{
		for (j = 0; FLAGS_CH[j]; j++)
		{
			if (format[i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}
		if (FLAGS_CH[j] == '\0')
			break;
	}
	*ind = i - 1;
	return (flags);
}

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @ind: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *ind)
{
	int i = *ind + 1;
	int size = 0;

	if (format[i] == 'l')
		size = LONG;
	else if (format[i] == 'h')
		size = SHORT;

	if (size == 0)
		*ind = i - 1;
	else
		*ind = i;

	return (size);
}
