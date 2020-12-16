/*
** EPITECH PROJECT, 2020
** CPool Day 08
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *result = NULL;

    if (src == NULL)
        return (NULL);
    result = malloc(sizeof(char) * my_strlen(src) + 1);
    if (result == NULL)
        return (NULL);
    for (i = 0; src[i]; i++)
        result[i] = src[i];
    result[i] = '\0';
    return (result);
}
