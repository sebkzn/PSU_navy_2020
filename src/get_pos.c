/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** get_pos
*/

#include <stdio.h>
#include "navy.h"

static void destroy_fp_and_array(boat_t **boat_array, FILE **fp)
{
    if (*fp)
        fclose(*fp);
    if (boat_array)
        free_double_array((void ***)&boat_array);
}

static boat_t *parse_pos(char *line)
{
    char **parsed = my_str_to_wordtab(line, ':');
    boat_t *boat = malloc(sizeof(boat_t));

    if (!parsed || !boat) {
        if (parsed)
            free_double_array((void ***)&parsed);
        if (boat)
            free(boat);
        return (NULL);
    }
    boat->length = my_getnbr(parsed[0]);
    boat->back = my_strdup(parsed[1]);
    boat->front = my_strdup(parsed[2]);
    free_double_array((void ***)&parsed);
    return (boat);
}

boat_t **fill_boat_array(char const *filename)
{
    boat_t **boat_array = malloc(sizeof(boat_t *) * 5);
    int i = 0;
    char *line = NULL;
    size_t len;
    FILE *fp = fopen(filename, "r");

    if (!boat_array || !fp) {
        destroy_fp_and_array(boat_array, &fp);
        return (NULL);}
    for (i = 0; getline(&line, &len, fp) != EOF; i++) {
        boat_array[i] = parse_pos(line);
        if (!boat_array[i]) {
            destroy_fp_and_array(boat_array, &fp);
            return (NULL);
        }
    }
    boat_array[i] = NULL;
    free(line);
    fclose(fp);
    return (boat_array);
}
