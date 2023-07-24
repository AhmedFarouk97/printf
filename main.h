#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define BUFFER_SIZE 1024

#define F_PLUS 2
#define F_HASH 8
#define F_SPACE 16

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
	int (*f)(va_list, char *, int);
} spec_t;

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...);
int print_c(va_list args, char *buffer, int flags);
int print_s(va_list args, char *buffer, int flags);
int print_5(va_list args, char *buffer, int flags);
int print_d(va_list args, char *buffer, int flags);
int print_b(va_list args, char *buffer, int flags);
int print_u(va_list args, char *buffer, int flags);
int print_o(va_list args, char *buffer, int flags);
int print_x(va_list args, char *buffer, int flags);
int print_X(va_list args, char *buffer, int flags);
int print_S(va_list args, char *buffer, int flags);
int print_p(va_list args, char *buffer, int flags);

int _putchar(char c);

int get_flags(const char *format, int *i);

int write_num(int ind, int is_negative, char *buffer, int flags);
long int convert_size_number(long int num, int size);

#endif /* MAIN_H */
