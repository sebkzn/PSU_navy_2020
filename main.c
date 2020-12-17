/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** main
*/

#include "navy.h"
#include <sys/types.h>
#include <signal.h>

status_t statusinfo = {0};

static void destruct_game(boat_t **boat_array)
{
    int i = 0;

    for (i = 0; boat_array[i] != NULL; i++) {
        free(boat_array[i]->back);
        free(boat_array[i]->front);
    }
    free_double_array((void ***)&boat_array);
}

int main(int argc, char * const *argv)
{
    boat_t **boat_array = NULL;

    if (argc != 2 && argc != 3)
        return (84);
    if (argc == 2) {
        boat_array = get_positions(argv[1]);
        if (!boat_array)
            return (84);
        create_game(boat_array);
    } else if (argc == 3) {
        boat_array = get_positions(argv[2]);
        if (!boat_array)
            return (84);
        connect_game((pid_t)my_getnbr(argv[1]), boat_array);
    }
    destruct_game(boat_array);
    return (0);
}
