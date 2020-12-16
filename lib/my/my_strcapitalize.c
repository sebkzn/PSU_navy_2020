/*
** EPITECH PROJECT, 2020
** CPool Day 06
** File description:
** my_strcapitalize
*/

static int my_char_is_alpha(char c)
{
    return (((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) ? 1 : 0);
}

static int my_char_is_lower(char c)
{
    return ((c >= 97 && c <= 122) ? 1 : 0);
}

static int my_char_is_upper(char c)
{
    return ((c >= 65 && c <= 90) ? 1 : 0);
}

char *my_strcapitalize(char *str)
{
    if (my_char_is_lower(str[0]))
        str[0] -= 32;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!my_char_is_alpha(str[i - 1]) && my_char_is_lower(str[i]))
            str[i] -= 32;
        if (str[i - 1] >= 48 && str[i - 1] <= 57 && my_char_is_upper(str[i]))
            str[i] += 32;
        if (my_char_is_lower(str[i - 1]) && my_char_is_upper(str[i]))
            str[i] += 32;
        if (my_char_is_upper(str[i - 1]) && my_char_is_upper(str[i]))
            str[i] += 32;
    }
    return (str);
}
