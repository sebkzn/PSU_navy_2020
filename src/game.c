/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** game
*/

#include <stdio.h>
#include "navy.h"
#include "signal_handler.h"

static int check_win(char **board, char **enemy_board)
{
    int my_x = 0;
    int enemy_x = 0;

    for (int i = 0; board[i] != NULL; i++)
        for (int j = 0; board[i][j]; j++)
            if (board[i][j] == 'x')
                my_x += 1;
    for (int i = 0; enemy_board[i] != NULL; i++)
        for (int j = 0; enemy_board[i][j]; j++)
            if (enemy_board[i][j] == 'x')
                enemy_x += 1;
    if (my_x >= 14) {
        my_printf("Enemy won\n\n");
        return (1);
    } else if (enemy_x >= 14) {
        my_printf("I won\n\n");
        return (1);
    }
    return (0);
}

void game_loop(pid_t enemypid, char **board, char **enemy_board, int turn)
{
    if (!board || !enemy_board)
        return;
    display_board(board, 0);
    display_board(enemy_board, 1);
    if (check_win(board, enemy_board))
        return;
    if (turn) {
        if (get_input(enemypid, &enemy_board))
            if (receive_attack(enemypid, &board))
                game_loop(enemypid, board, enemy_board, 1);
    } else {
        if (receive_attack(enemypid, &board))
            if (get_input(enemypid, &enemy_board))
                game_loop(enemypid, board, enemy_board, 0);
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
        free_double_array((void ***)&my_board);
        free_double_array((void ***)&enemy_board);
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
        free_double_array((void ***)&my_board);
        free_double_array((void ***)&enemy_board);
    }
}
