/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** board
*/

#include "navy.h"

static void place_boats(char ***board, boat_t **boats)
{
    int pos1 = 0;
    int pos2 = 0;

    if (!boats)
        return;
    for (int i = 0; boats[i] != NULL; i++) {
        if (boats[i]->back[0] == boats[i]->front[0]) {
            pos1 = MIN(boats[i]->front[1] - 48, boats[i]->back[1] - 48);
            pos2 = boats[i]->back[0] - 65;
            for (size_t k = pos1 - 1, j = 0; j < boats[i]->length; k++, j++)
                (*board)[k][pos2] = boats[i]->length + 48;
        } else if (boats[i]->back[1] == boats[i]->front[1]) {
            pos2 = MIN(boats[i]->front[0] - 65, boats[i]->back[0] - 65);
            pos1 = boats[i]->back[1] - 48;
            for (size_t k = pos2, j = 0; j < boats[i]->length; k++, j++)
                (*board)[pos1 - 1][k] = boats[i]->length + 48;
        }
    }
}

void display_board(char **board, int enemy)
{
    my_printf(!enemy ? "my positions:\n" : "enemy's positions:\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (int j = 1, i = 0; board[i] != NULL; i++, j++) {
        my_printf("%d|", j);
        for (int k = 0; board[i][k]; k++) {
            my_putchar(board[i][k]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
    my_putchar('\n');
}

char **create_board(boat_t **boats)
{
    int i = 0;
    char **board = malloc(sizeof(char *) * (8 + 1));

    if (!board)
        return (NULL);
    for (i = 0; i < 8; i++) {
        board[i] = malloc(sizeof(char) * 8 + 1);
        if (!board[i])
            return (NULL);
    }
    board[i] = NULL;
    for (int j = 0, i = 0; board[i] != NULL; i++) {
        for (j = 0; j < 8; j++)
            board[i][j] = '.';
        board[i][j] = '\0';
    }
    place_boats(&board, boats);
    return (board);
}
