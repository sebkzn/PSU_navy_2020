/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** attack
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

int receive_attack(pid_t enemypid, char ***board)
{
    char atk[3] = {0};
    int i = 'A';
    int j = '1';
    int k;

    my_printf("waiting for enemy's attack...\n");
    signal(SIGUSR1, &atk_pos);
    signal(SIGUSR2, &atk_pos);
    while (!statusinfo.received)
        pause();
    for (i = 'A', k = 1; k < statusinfo.count; i++, k++);
    statusinfo.received = 0;
    statusinfo.count = 0;
    while (!statusinfo.received)
        pause();
    for (j = '1', k = 0; k < statusinfo.count; j++, k++);
    atk[0] = i;
    atk[1] = j;
    if ((*board)[j - 49][i - 65] == '.' || (*board)[j - 49][i - 65] == 'x' ||
        (*board)[j - 49][i - 65] == 'o') {
        send_signal(enemypid, SIGUSR2);
        my_printf("%s: missed\n\n", atk);
        (*board)[j - 49][i - 65] = 'o';
    } else {
        send_signal(enemypid, SIGUSR1);
        my_printf("%s: hit\n\n", atk);
        (*board)[j - 49][i - 65] = 'x';
    }
    return (1);
}

int send_attack(pid_t enemypid, char *atk)
{
    for (int i = 'A'; i <= atk[0]; i++)
        if (!send_signal(enemypid, SIGUSR1))
            return (0);
    if (!send_signal(enemypid, SIGUSR2))
        return (0);
    for (int i = '1'; i < atk[1]; i++)
        if (!send_signal(enemypid, SIGUSR1))
            return (0);
    if (!send_signal(enemypid, SIGUSR2))
        return (0);
    signal(SIGUSR1, &is_hit);
    signal(SIGUSR2, &is_hit);
    pause();
    if (statusinfo.received) {
        statusinfo.received = 0;
        return (1);
    }
    return (0);
}

int get_input(pid_t enemypid, char ***enemy)
{
    ssize_t rvalue = 0;
    size_t len;
    char *buff = NULL;
    int check;

    while (rvalue <= 0 || !check) {
        my_printf("attack: ");
        rvalue = getline(&buff, &len, stdin);
        buff[2] = '\0';
        check = check_input(rvalue, buff);
    }
    if (send_attack(enemypid, buff)) {
        (*enemy)[buff[1] - 49][buff[0] - 65] = (statusinfo.hit ? 'x' : 'o');
        my_printf((statusinfo.hit ? "%s: hit\n" : "%s: missed\n"), buff);
        my_putchar('\n');
        return (1);
    }
    return (0);
}
