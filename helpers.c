#include "main.h"
/**
 * convert_int - converts number
 * @num: number to be converted
 * @size: get size
 *
 * Return: num
 */
int convert_int(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}
/**
 * convert_uint - converts usnsignd numbers
 * @num: number to be converted
 * @size: get size
 *
 * Return: num
 */
int convert_uint(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
