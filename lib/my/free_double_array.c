/*
** EPITECH PROJECT, 2020
** B-CPE-110-NCY-1-1-BSQ-sebastien.raoult
** File description:
** free_double_array
*/

#include <stdlib.h>

void free_double_array(void ***array)
{
    int i = 0;

    for (i = 0; (*array)[i]; i++)
        free((*array)[i]);
    free(*array);
}
