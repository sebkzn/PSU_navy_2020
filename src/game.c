/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** game
*/

#include "navy.h"
#include "signal_handler.h"

void game_loop(pid_t enemypid, boat_t **boats, char **board)
{
    char **enemy_board = create_board(NULL);

    if (!board || !enemy_board)
        return;
    display_board(board, 1);
    my_putchar('\n');
    display_board(enemy_board, 0);
}

void connect_game(pid_t pid, boat_t **boats)
{
    char **my_board = NULL;

    my_printf("my_pid: %d\n", getpid());
    usleep(10);
    if (kill(pid, SIGUSR2) < 0)
        return;
    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        my_board = create_board(boats);
        game_loop(pid, boats, my_board);
    }
}

void create_game(boat_t **boats)
{
    char **my_board = NULL;

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");

    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        usleep(10);
        if (kill(statusinfo.pid, SIGUSR1) != -1) {
            my_board = create_board(boats);
            game_loop(statusinfo.pid, boats, my_board);
        } else
            return;
    }
}
