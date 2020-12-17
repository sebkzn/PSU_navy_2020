/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** signal_handler
*/

#ifndef SIGNAL_HANDLER_H_
#define SIGNAL_HANDLER_H_

#include "errno.h"
#include <sys/types.h>
#include <signal.h>

void sig_handler(int sig, siginfo_t *siginfo, void *context);
int get_signals(int sig_one, int sig_two);

#endif /* !SIGNAL_HANDLER_H_ */
