#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
/**
 * struct specifier - Struct to map format specifiers to their corresponding
 * printing function
 *
 * @spec: The format specifier
 * @f: The printing function
 */
typedef struct specifier
{
	char *spec;
	int (*f)(va_list);
} spec_t;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_p(va_list args);
int print_d(va_list args);

int _putchar(char c);

#endif /* MAIN_H */
