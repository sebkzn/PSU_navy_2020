/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCY-1-1-myprintf-sebastien.raoult
** File description:
** myprintf
*/

#ifndef MYPRINTF_H_
#define MYPRINTF_H_

#include <unistd.h>
#include <stdarg.h>

int print_int(va_list ap);
int print_uint(va_list ap);
int print_binary(va_list ap);
int print_octal(va_list ap);
int print_hexa_lower(va_list ap);
int print_hexa_upper(va_list ap);
int print_char(va_list ap);
int print_str(va_list ap);
int print_ptr(va_list ap);
int print_nonprintable(va_list ap);
int print_percent(va_list ap);

typedef struct flag_func_s {
    char flag;
    int (*get_flag)(va_list ap);
} flag_func_t;

const flag_func_t flag_array[] = {
    {'d', &print_int},
    {'i', &print_int},
    {'u', &print_uint},
    {'b', &print_binary},
    {'o', &print_octal},
    {'x', &print_hexa_lower},
    {'X', &print_hexa_upper},
    {'c', &print_char},
    {'s', &print_str},
    {'p', &print_ptr},
    {'S', &print_nonprintable},
    {'%', &print_percent},
    {-1, NULL}
};

#endif /* !MYPRINTF_H_ */
