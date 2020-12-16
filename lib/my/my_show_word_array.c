/*
** EPITECH PROJECT, 2020
** CPool Day 08
** File description:
** my_show_word_array
*/

#include "my.h"
#include <unistd.h>

int my_show_word_array(char * const *tab)
{
    if (tab == NULL || tab[0] == NULL)
        return (0);
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
