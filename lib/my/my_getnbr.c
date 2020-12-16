/*
** EPITECH PROJECT, 2020
** CPool Day 04
** File description:
** my_get_nbr
*/

#include <limits.h>

int my_getnbr(char const *str)
{
    long long result = 0;
    int i = 0;
    int sign = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    for (; str[i] != 0 && str[i] >= '0' && str[i] <= '9'; i++) {
        result = result * 10;
        result += str[i] - 48;
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            return (0);
    }
    return (result * sign);
}
