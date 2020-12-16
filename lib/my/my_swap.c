/*
** EPITECH PROJECT, 2020
** CPool Day 04
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
