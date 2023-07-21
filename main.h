#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct specifier - struct for valid format specifiers
 * @valid_types: valid types for format specifier
 * @f: pointer to function for format specifier
 */
typedef struct specifier
{
	char *valid_types;
	int (*f)(va_list);
} specifier_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_integer_helper(int num);

#endif /* MAIN_H */
