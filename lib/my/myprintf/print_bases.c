/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCY-1-1-myprintf-sebastien.raoult
** File description:
** print_bases
*/

#include <stdarg.h>
#include "my.h"

int print_binary(va_list ap)
{
    int r_value = 0;

    r_value = my_putnbr_base(va_arg(ap, unsigned int), "01");
    return (r_value);
}

int print_octal(va_list ap)
{
    int r_value = 0;

    r_value = my_putnbr_base(va_arg(ap, unsigned int), "01234567");
    return (r_value);
}

int print_hexa_lower(va_list ap)
{
    int r_value = 0;

    r_value = my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
    return (r_value);
}

int print_hexa_upper(va_list ap)
{
    int r_value = 0;

    r_value = my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
    return (r_value);
}
