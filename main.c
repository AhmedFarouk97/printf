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
    short int si = SHRT_MAX;
    int i = INT_MAX;
    long int li = LONG_MAX;
    unsigned short int usi = USHRT_MAX;
    unsigned int ui = UINT_MAX;
    unsigned long int uli = ULONG_MAX;

    /* Test the h flag with integer conversions */
    printf("Short int: %hd\n", si); /* Should print "si: 32767" */
    _printf("Short int: %hd\n", si); /* Should print "si: 32767" */
    printf("int: %d\n", i); /* Should print "i: 2147483647" */
    _printf("int: %d\n", i); /* Should print "i: 2147483647" */
    printf("Long int: %ld\n", li); /* Should print "li: 9223372036854775807" */
    _printf("Long int: %ld\n", li); /* Should print "li: 9223372036854775807" */
    printf("Unsigned short int: %hu\n", usi); /* Should print "usi: 65535" */
    _printf("Unsigned short int: %hu\n", usi); /* Should print "usi: 65535" */
    printf("Unsigned int: %u\n", ui); /* Should print "ui: 4294967295" */
    _printf("Unsigned int: %u\n", ui); /* Should print "ui: 4294967295" */
    printf("Unsigned long int: %lu\n", uli); /* Should print "uli: 18446744073709551615" */
	_printf("Unsigned long int: %lu\n", uli); /* Should print "uli: 18446744073709551615" */
    return (0);
}
