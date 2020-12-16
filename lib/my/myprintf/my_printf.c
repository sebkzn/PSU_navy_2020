/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCY-1-1-myprintf-sebastien.raoult
** File description:
** myprintf
*/

#include "my.h"
#include "my_printf.h"

static int print_flag(char c, va_list ap)
{
    int i = 0;
    int r_value = 0;
    const char unknown[3] = {'%', c, 0};

    for (i = 0; flag_array[i].flag != -1; i++) {
        if (flag_array[i].flag == c) {
            r_value = flag_array[i].get_flag(ap);
            break;
        }
    }
    if (flag_array[i].flag == -1) {
        my_putstr(unknown);
        r_value = 2;
    }
    return (r_value);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int r_value = 0;
    int j = 0;
    va_list ap;

    va_start(ap, format);
    for (i = 0; format[i]; i++) {
        if (format[i] == '%') {
            i += 1;
            r_value += print_flag(format[i], ap);
        } else {
            my_putchar(format[i]);
            j++;
        }
    }
    va_end(ap);
    return (r_value + j);
}
