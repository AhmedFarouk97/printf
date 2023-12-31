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

#define LONG 2
#define SHORT 1

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
	int (*f)(va_list, int, int);
} spec_t;

void print_buffer(char *buffer, int *buff_ind);
int _printf(const char *format, ...);

int print_c(va_list args, int flags, int size);
int print_s(va_list args, int flags, int size);
int print_5(va_list args, int flags, int size);
int print_d(va_list args, int flags, int size);
int print_b(va_list args, int flags, int size);
int print_u(va_list args, int flags, int size);
int print_o(va_list args, int flags, int size);
int print_x(va_list args, int flags, int size);
int print_X(va_list args, int flags, int size);
int print_S(va_list args, int flags, int size);
int print_p(va_list args, int flags, int size);

int get_flags(const char *format, int *ind);
int get_size(const char *format, int *ind);

long int convert_uint(unsigned long int num, int size);
long int convert_int(long int num, int size);
#endif /* MAIN_H */
