/*
** EPITECH PROJECT, 2020
** CPool Day 05
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i = nb;

    if (nb <= 1)
        return (2);
    while (1) {
        if (my_is_prime(i))
            break;
        i++;
    }
    return (i);
}
