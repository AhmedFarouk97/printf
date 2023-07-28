#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024

#define PLUS 1
#define SPACE 2
#define HASH 3

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
	int (*f)(va_list, int);
} spec_t;

void print_buffer(char *buffer, int *buff_ind);
int _printf(const char *format, ...);

int print_c(va_list args, int flags);
int print_s(va_list args, int flags);
int print_5(va_list args, int flags);
int print_d(va_list args, int flags);
int print_b(va_list args, int flags);
int print_u(va_list args, int flags);
int print_o(va_list args, int flags);
int print_x(va_list args, int flags);
int print_X(va_list args, int flags);
int print_S(va_list args, int flags);
int print_p(va_list args, int flags);

int get_flags(const char *format, int *ind);

#endif /* MAIN_H */
