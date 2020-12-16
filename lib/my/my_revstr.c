/*
** EPITECH PROJECT, 2020
** CPool Day 06
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    char tmp;
    int len = 0;

    for (len = 0; str[len] != '\0'; len++);
    len -= 1;
    for (int i = 0; i < len; i++, len--) {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
    }
    return (str);
}
