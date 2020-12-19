/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** game
*/

#include <stdio.h>
#include "navy.h"
#include "signal_handler.h"

void game_loop(pid_t enemypid, char **board, char **enemy_board, int turn)
{
    if (!board || !enemy_board)
        return;
    display_board(board, 0);
    display_board(enemy_board, 1);
    if (turn) {
        if (get_input(enemypid, &enemy_board)) {
            receive_attack(enemypid, &board);
            game_loop(enemypid, board, enemy_board, 1);
        }
    } else {
        if (receive_attack(enemypid, &board)) {
            get_input(enemypid, &enemy_board);
            game_loop(enemypid, board, enemy_board, 0);
        }
    }
}

void connect_game(pid_t pid, boat_t **boats)
{
    char **my_board = NULL;
    char **enemy_board = NULL;

    my_printf("my_pid: %d\n", getpid());
    usleep(500);
    if (kill(pid, SIGUSR2) < 0)
        return;
    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        my_board = create_board(boats);
        enemy_board = create_board(NULL);
        game_loop(pid, my_board, enemy_board, 0);
    }
}

void create_game(boat_t **boats)
{
    char **my_board = NULL;
    char **enemy_board = NULL;

    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");

    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        usleep(500);
        if (kill(statusinfo.pid, SIGUSR1) != -1) {
            my_board = create_board(boats);
            enemy_board = create_board(NULL);
            game_loop(statusinfo.pid, my_board, enemy_board, 1);
        } else
            return;
    }
}
