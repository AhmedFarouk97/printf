#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#define BUFFER_SIZE 1024
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

int handle_specifiers(const char *format,
		va_list args, char buffer[], int *buff_ind);
int handle_specifier(const char *format,
		va_list args, char buffer[], int *buff_ind);
void print_output(char buffer[], int *buff_ind, int count);
int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);

int print_S(va_list args);
int hex_print(unsigned int num);


int print_pointer(va_list args);
int print_unsigned_long_hex(unsigned long int n);

int print_rot13(va_list args);

#endif /* MAIN_H */
