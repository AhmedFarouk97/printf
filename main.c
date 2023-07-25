#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned int n = 0;

	/* hash */
	printf("Plus flag:\n");
	printf("%#o\n", n);
	_printf("%#o\n", n);
	printf("%#x\n", n);
	_printf("%#x\n", n);
	printf("%#X\n", n);
	_printf("%#X\n", n);

	return (0);
}
