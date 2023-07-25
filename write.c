#include "main.h"
/**
 * write_num - printing number with flags
 * @ind: passed index
 * @is_negative: 1 if negative 0 if not
 * @buffer: passed pointer to buffer
 * @flags: passed flags
 *
 * Return: the length of printed characgters
 */
int write_num(int ind, int is_negative, char *buffer, int flags)
{
	int length = BUFFER_SIZE - ind - 1;
	char extra_ch = 0;

	if (is_negative)
		extra_ch = '-';
	else if (flags & F_SPACE)
		extra_ch = ' ';
	else if (flags & F_PLUS)
		extra_ch = '+';

	if (extra_ch != 0)
		length++;
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - printing pointer with flags
 * @ind: passed index
 * @buffer: passed pointer to buffer
 * @flags: passed flags
 *
 * Return: the length of printed characgters
 */
int write_pointer(int ind, char *buffer, int flags)
{
	int length = BUFFER_SIZE - ind - 1;
	char extra_ch = 0;

	if (flags & F_SPACE)
		extra_ch = ' ';
	else if (flags & F_PLUS)
		extra_ch = '+';

	if (extra_ch != 0)
		length++;
	if (extra_ch)
		buffer[--ind] = extra_ch;
	return (write(1, &buffer[ind], length));
}
