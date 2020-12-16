/*
** EPITECH PROJECT, 2020
** CPool Day 06
** File description:
** my_stnrcmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (n <= 0)
        return (0);
    while (n && *s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
        n--;
    }
    return (*s1 - *s2);
}
