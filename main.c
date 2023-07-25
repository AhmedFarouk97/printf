#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void) {

    int len;
    int len2;
	int n = 0x123;
    unsigned int ui;
    void *addr;



    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
	_printf("int min: %d\n", INT_MIN);
	printf("int min: %d\n", INT_MIN);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -2147483647);
    printf("Negative:[%d]\n\n", -2147483647);

	_printf("%b\n\n", 98);

    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n\n");
	

	_printf("%x\n", n);  
	_printf("%#x\n", n);
	_printf("%X\n", n); 
	_printf("%#X\n", n);
	_printf("%x\n", 0123);
	_printf("%#x\n", 0123);

	printf("%x\n", n);  
	printf("%#x\n", n);
	printf("%X\n", n); 
	printf("%#X\n", n);
	printf("%x\n", 0123);
	printf("%#x\n", 0123);

    _printf("%i\n", 1234567);
    printf("%i\n", 1234567);
	putchar('\n');
    _printf("%ld\n", 1234567890123456L);
    printf("%ld\n", 1234567890123456L);
	putchar('\n');
    _printf("%hd\n", (short)12345);
    printf("%hd\n", (short)12345);
	putchar('\n');
    _printf("%u\n", 1234567890U);
    printf("%u\n", 1234567890U);
	putchar('\n');
    _printf("%lu\n", 1234567890123456UL);
    printf("%lu\n", 1234567890123456UL);
	putchar('\n');
    _printf("%ho\n", 01234567);
    printf("%ho\n", 01234567);
	putchar('\n');
    _printf("%hx\n", 0x12345);
    printf("%hx\n", 0x12345);
	putchar('\n');
    _printf("%hX\n", 0xABCDEF);
    printf("%hX\n", 0xABCDEF);
	putchar('\n');

    /* Test the '+' and 'space' flags with '%d' and '%i' */
	printf("Testing + and ' ' flag with _printf:\n");
    _printf("%d %d %d %d %d");
	putchar('\n');
	printf("Testing + and ' ' flag with printf:\n");
	putchar('\n');
    /* Test the '#' flag with '%o', '%x', and '%X' */
	printf("Testing # flag with _prinf:\n");
    _printf("%#o %#x %#X\n", 42, 42, 42);
	printf("Testing # flag with prinf:\n");
    return (0);

}
