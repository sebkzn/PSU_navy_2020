/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCY-1-1-myprintf-sebastien.raoult
** File description:
** print_integer
*/

#include <stdarg.h>
#include "my.h"

int print_int(va_list ap)
{
    int nb = va_arg(ap, int);
    int nb_digit = 0;

    my_put_nbr(nb);
    if (nb < 0) {
        if (nb == -2147483648)
            return (11);
        nb_digit++;
        nb *= -1;
    }
    while (nb > 0) {
        nb /= 10;
        nb_digit++;
    }
    return (nb_digit);
}

int print_uint(va_list ap)
{
    int r_value = 0;

    r_value = my_putnbr_base(va_arg(ap, unsigned int), "0123456789");
    return (r_value);
}

int print_char(va_list ap)
{
    my_putchar(va_arg(ap, unsigned int));
    return (1);
}

int print_percent(void)
{
    my_putchar('%');
    return (1);
}
