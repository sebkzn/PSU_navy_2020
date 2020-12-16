/*
** EPITECH PROJECT, 2020
** CPool Day 08
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

static int count_words(char const *str, char sep)
{
    int res = 0;

    for (int i = 0; str[i]; i++)
        if ((str[i] != sep && str[i + 1] == sep) ||
            (str[i] != sep && str[i + 1] == 0))
            res++;
    return (res);
}

static char *get_word(char const *str, int i, int mark)
{
    char *result = NULL;

    i -= mark;
    result = malloc(sizeof(char) * mark + 1);
    if (result == NULL)
        return (NULL);
    result[mark] = '\0';
    for (int j = 0; j != mark; j++)
        result[j] = str[i + j];
    return (result);
}

char **my_str_to_wordtab(char const *str, char sep)
{
    char **result = NULL;
    int nb_words = count_words(str, sep);
    int j = 0;
    int mark = 0;

    result = (nb_words > 0) ? malloc(sizeof(char *) * (nb_words + 1)) : NULL;
    if (result == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if ((str[i] != sep && str[i + 1] == sep) ||
            (str[i] != sep && str[i + 1] == '\0')) {
            result[j] = get_word(str, i + 1, mark + 1);
            j++;
            mark = 0;
        } else if (str[i] != sep)
            mark++;
    }
    result[nb_words] = NULL;
    return (result);
}
