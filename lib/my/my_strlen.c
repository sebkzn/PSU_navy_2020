/*
** EPITECH PROJECT, 2020
** CPool Day 04
** File description:
** my_strlen
*/

#include <unistd.h>

size_t my_strlen(char const *str)
{
    size_t len = 0;

    if (str == NULL || str[0] == 0)
        return (0);
    for (len = 0; str[len] != '\0'; len++);
    return (len);
}
