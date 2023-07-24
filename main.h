#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024
/**
 * struct specifier - Struct to map format specifiers to their corresponding
 * printing function
 *
 * @spec: The format specifier
 * @f: The printing function
 */
typedef struct specifier
{
	char spec;
	int (*f)(va_list, char *);
} spec_t;

int _printf(const char *format, ...);
int print_c(va_list args, char *buffer);
int print_s(va_list args, char *buffer);
int print_p(va_list args, char *buffer);
int print_d(va_list args, char *buffer);
int print_b(va_list args, char *buffer);
int print_u(va_list args, char *buffer);
int print_o(va_list args, char *buffer);
int print_x(va_list args, char *buffer);
int print_X(va_list args, char *buffer);
int print_S(va_list args, char *buffer);

int _putchar(char c);

#endif /* MAIN_H */
