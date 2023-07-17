#ifndef franco_h
#define franco_h
#include <stdarg.h>

/**
 * struct type - Struct type.
 *
 * @ty: The operador.
 * @f: The function associated.
 */

typedef struct ty
{
	char ty;
	int (*fn)(va_list ap, int c);
}ty_f;

int _printf(const char *format, ...);

int count_chars(const char*);

int (*get_type(char f))(va_list ap, int c);

int special_case(const char *f);

int _putchar(char c);

char *_itoa(unsigned int n, char a[]);

int print_char(va_list ap, int c);

int print_str(va_list ap, int c);

int print_num(va_list ap, int c);

#endif
