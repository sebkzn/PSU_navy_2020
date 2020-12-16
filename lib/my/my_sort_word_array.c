/*
** EPITECH PROJECT, 2020
** CPool Day 10
** File description:
** my_sort_word_array
*/

#include <unistd.h>
#include "my.h"

int my_sort_word_array(char **tab)
{
    char *tmp;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = i + 1; tab[j] != NULL; j++) {
            if (my_strcmp(tab[i], tab[j]) > 0) {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }
    return (0);
}
