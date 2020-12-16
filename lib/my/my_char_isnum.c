/*
** EPITECH PROJECT, 2020
** CPool EvalExpr
** File description:
** my_char_isnum
*/

int my_char_isnum(char c)
{
    return ((c >= 48 && c <= 57) || (c == '-' || c == '+'));
}
