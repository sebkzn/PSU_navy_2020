/*
** EPITECH PROJECT, 2020
** CPool Day 07
** File description:
** my_strcat
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int d_len = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[d_len + i] = src[i];
    dest[d_len + i] = '\0';
    return (dest);
}
