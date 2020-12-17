/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** game
*/

#include <stdio.h>
#include "navy.h"
#include "signal_handler.h"

int check_input(ssize_t rvalue, char *buffer)
{
    if (!buffer)
        return (0);
    if (rvalue != 3) {
        my_printf("wrong position\n");
        return (0);
    } else if (buffer[0] < 'A' || buffer[0] > 'H' || buffer[1] < '1' ||
                buffer[1] > '8') {
        my_printf("wrong position\n");
        return (0);
    }
    return (1);
}

void game_loop(pid_t enemypid, boat_t **boats, char **board, int turn)
{
    char **enemy_board = create_board(NULL);
    size_t len;
    int check = 0;
    ssize_t rvalue = 0;
    char *buff = NULL;

    if (!board || !enemy_board)
        return;
    display_board(board, 0);
    display_board(enemy_board, 1);
    if (turn) {
        while (rvalue <= 0 || !check) {
            my_printf("attack: ");
            rvalue = getline(&buff, &len, stdin);
            buff[2] = '\0';
            check = check_input(rvalue, buff);
        }
        my_printf("%s: missed\n\n", buff);
        game_loop(enemypid, boats, board, 0);
    } else {
        my_printf("waiting for enemy's attack...\n");
        pause();
    }
}

void connect_game(pid_t pid, boat_t **boats)
{
    char **my_board = NULL;

    my_printf("my_pid: %d\n", getpid());
    usleep(500);
    if (kill(pid, SIGUSR2) < 0)
        return;
    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        my_board = create_board(boats);
        game_loop(pid, boats, my_board, 0);
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
        usleep(500);
        if (kill(statusinfo.pid, SIGUSR1) != -1) {
            my_board = create_board(boats);
            game_loop(statusinfo.pid, boats, my_board, 1);
        } else
            return;
    }
}
