/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** get_pos
*/

#include <stdio.h>
#include "navy.h"

static int boat_is_linear(char **pos)
{
    int len = my_getnbr(pos[0]);
    int check = 0;

    if (pos[1][0] == pos[2][0]) {
        check = (MY_ABS((pos[1][1] - pos[2][1])) == MY_ABS((len - 1)) ? 1 : 0);
    } else if (pos[1][1] == pos[2][1]) {
        check = (MY_ABS((pos[1][0] - pos[2][0])) == MY_ABS((len - 1)) ? 1 : 0);
    }
    free_double_array((void ***)&pos);
    return (check);
}

static int check_coord(char *back, char *front)
{
    return (my_strlen(back) != 2 || my_strlen(front) != 2 ||
            back[0] < 'A' || back[0] > 'H' || front[0] < 'A' || front[0] > 'H'
            || back[1] < '1' || back[1] > '8' || front[1] < '1' ||
            front[1] > '8');
}

static int check_line(char *line)
{
    int i = 0;
    char **parsed = my_str_to_wordtab(line, ':');

    if (!parsed)
        return (0);
    for (i = 0; parsed[i] != NULL; i++);
    if (i != 3) {
        free_double_array((void ***)&parsed);
        return (0);
    }
    if (my_getnbr(parsed[0]) < 2 || my_getnbr(parsed[0]) > 5) {
        free_double_array((void ***)&parsed);
        return (0);
    }
    if (!check_coord(parsed[1], parsed[2])) {
        free_double_array((void ***)&parsed);
        return (0);
    }
    return (boat_is_linear(parsed));
}

static int check_pos_file(char const *filename)
{
    char *line = NULL;
    size_t len;
    int i = 0;
    FILE *fp = fopen(filename, "r");

    if (!fp)
        return (0);
    for (i = 0; getline(&line, &len, fp) != EOF; i++) {
        if (!check_line(line)) {
            free(line);
            fclose(fp);
            return (0);
        }
    }
    free(line);
    fclose(fp);
    return (i != 4 ? 0 : 1);
}

boat_t **get_positions(char const *filename)
{
    boat_t **boats = NULL;

    if (!filename)
        return (NULL);
    if (!check_pos_file(filename))
        return (NULL);
    boats = fill_boat_array(filename);
    for (int i = 0; boats[i] != NULL; i++)
        for (int j = i + 1; boats[j] != NULL; j++)
            if (boats[i]->length == boats[j]->length) {
                destruct_game(boats);
                return (NULL);
            }
    return (boats);
}
