/*
** EPITECH PROJECT, 2020
** CPool Day 04
** File description:
** my_putstr
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL || str[0] == 0)
        return (0);
    for (i = 0; str[i]; i++);
    write(1, str, i);
    return (0);
}
