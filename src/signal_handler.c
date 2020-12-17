/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** signal_handler
*/

#include "my.h"
#include "navy.h"
#include "signal_handler.h"

void sig_handler(int sig, siginfo_t *siginfo, void *context)
{
    if (sig == SIGUSR1) {
        my_printf("successfully connected\n\n");
    } else if (sig == SIGUSR2) {
        statusinfo.pid = siginfo->si_pid;
        my_printf("enemy connected\n\n");
    }
    statusinfo.received = 1;
}

int get_signals(int sig_one, int sig_two)
{
    struct sigaction action = {0};

    action.sa_sigaction = &sig_handler;
    action.sa_flags = SA_SIGINFO;

    if (sigaction(sig_one, &action, NULL) == -1 ||
        sigaction(sig_two, &action, NULL) == -1)
        my_puterror("error with sigaction\n");
    else
        return (1);
    return (0);
}
