/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCY-1-1-myprintf-sebastien.raoult
** File description:
** print_str
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int print_str(va_list ap)
{
    char *str = my_strdup(va_arg(ap, char *));
    int len = 0;

    if (str == NULL) {
        my_putstr("(null)");
        return (6);
    }
    my_putstr(str);
    len = my_strlen(str);
    free(str);
    return (len);
}

int print_ptr(va_list ap)
{
    int r_value = 0;
    long unsigned int ptr = va_arg(ap, unsigned long);

    if (ptr == 0) {
        my_putstr("(nil)");
        return (5);
    }
    my_putstr("0x");
    r_value = my_putnbr_base(ptr, "0123456789abcdef");
    return (r_value + 2);
}

int print_nonprintable(va_list ap)
{
    char *str = my_strdup(va_arg(ap, char *));
    int len = 0;
    int i = 0;

    if (str == NULL) {
        my_putstr("(null)");
        return (6);
    }
    for (i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            len += 1;
            len += my_put_nonprintable((unsigned int)(str[i]), "01234567");
        } else {
            my_putchar(str[i]);
            len += 1;
        }
    }
    free(str);
    return (len);
}
