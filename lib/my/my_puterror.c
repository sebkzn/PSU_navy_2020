/*
** EPITECH PROJECT, 2020
** CPool Day 10
** File description:
** my_puterror
*/

#include <unistd.h>

void my_puterror(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != 0; i++);
    write(2, str, i);
}
