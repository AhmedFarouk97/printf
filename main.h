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

#define S_LONG 2
#define S_SHORT 1
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
	int (*f)(va_list, char *, int, int, int, int);
} spec_t;

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...);
int print_c(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_s(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_5(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_d(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_b(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_u(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_o(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_x(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_X(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_S(va_list args, char *buffer, int flags, int size,
		int percision, int width);
int print_p(va_list args, char *buffer, int flags, int size,
		int percision, int width);

int _putchar(char c);
int is_digit(char c);

int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_width(const char *format, int *i, va_list list);

int write_num(int ind, int is_negative, char *buffer, int flags);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
