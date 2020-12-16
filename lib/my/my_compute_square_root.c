/*
** EPITECH PROJECT, 2020
** CPool Day 05
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    if (nb <= 0)
        return (0);
    for (int i = 1; i < nb; i++)
        if (i * i == nb)
            return (i);
    return ((nb == 1) ? 1 : 0);
}
