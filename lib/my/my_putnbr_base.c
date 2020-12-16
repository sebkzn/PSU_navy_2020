/*
** EPITECH PROJECT, 2020
** B-PSU-100-NCY-1-1-myprintf-sebastien.raoult
** File description:
** my_put_base
*/

#include "my.h"

static int calc_r_value(unsigned long nb, unsigned long ret, size_t base_len)
{
    int r_value = 0;

    while ((nb / ret) >= base_len) {
        ret *= base_len;
    }
    while (ret > 0) {
        r_value++;
        ret /= base_len;
    }
    return (r_value);
}

int my_putnbr_base(unsigned long nb, char *base)
{
    size_t base_len = my_strlen(base);
    unsigned long ret = 1;
    int r_value = calc_r_value(nb, ret, base_len);

    for (ret = 1; (nb / ret) >= base_len; ret *= base_len);
    while (ret > 0) {
        my_putchar(base[(nb / ret) % base_len]);
        ret /= base_len;
    }
    return (r_value);
}

int my_put_nonprintable(unsigned long nb, char *base)
{
    size_t base_len = my_strlen(base);
    unsigned long ret = 1;
    int i = 0;
    int j = 0;
    int r_value = calc_r_value(nb, ret, base_len);
    char *res = malloc(r_value + 1);

    for (ret = 1; (nb / ret) >= base_len; ret *= base_len);
    while (ret > 0) {
        res[i++] = base[(nb / ret) % base_len];
        ret /= base_len;
    }
    res[i] = 0;
    for (j = my_strlen(res); j < 3; j++)
        my_putchar('0');
    my_putstr(res);
    free(res);
    return ((r_value >= 3) ? r_value : r_value + (j - 1));
}
