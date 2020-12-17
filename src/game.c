/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** game
*/

#include "navy.h"
#include "signal_handler.h"

void game_loop(pid_t enemypid, boat_t **boats)
{
    my_printf("my_positions:\n");
}

void connect_game(pid_t pid, boat_t **boats)
{
    my_printf("my_pid: %d\n", getpid());
    usleep(10);
    kill(pid, SIGUSR2);
    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        game_loop(pid, boats);
    }
}

void create_game(boat_t **boats)
{
    my_printf("my_pid: %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");

    get_signals(SIGUSR1, SIGUSR2);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        usleep(10);
        if (kill(statusinfo.pid, SIGUSR1) != -1)
            game_loop(statusinfo.pid, boats);
    }
}
