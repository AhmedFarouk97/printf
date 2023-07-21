#include "main.h"

int main(void)
{
	_printf("Hello, %s!\n", "world");
	_printf("This %c is a char: %c\n", 'd', 'r');
	_printf("The percent sign: %%\n");
	_printf("number %d is an integer\n", 5);
	_printf("number %i is an integer\n", 5);
	_printf("this %z is not a specifier%\n");

	return (0);
}

