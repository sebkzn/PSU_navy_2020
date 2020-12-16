/*
** EPITECH PROJECT, 2020
** CPool Day 08
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

static int my_char_isalphanum(char c)
{
    return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ||
            (c >= 48 && c <= 57) ? 1 : 0);
}

static int count_words(char const *str)
{
    int res = 0;

    for (int i = 0; str[i]; i++)
        if ((!my_char_isalphanum(str[i]) && my_char_isalphanum(str[i + 1])) ||
            (my_char_isalphanum(str[i]) && str[i + 1] == 0))
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

char **my_str_to_word_array(char const *str)
{
    char **result = NULL;
    int nb_words = count_words(str);
    int j = 0;
    int mark = 0;

    result = malloc(sizeof(char *) * (nb_words + 1));
    if (result == NULL)
        return (NULL);
    for (int i = 0; str[i]; i++) {
        if ((my_char_isalphanum(str[i]) && !my_char_isalphanum(str[i + 1])) ||
            (my_char_isalphanum(str[i]) && str[i + 1] == '\0')) {
            result[j] = get_word(str, i + 1, mark + 1);
            j++;
            mark = 0;
        } else if (my_char_isalphanum(str[i]))
            mark++;
    }
    result[nb_words] = NULL;
    return (result);
}
