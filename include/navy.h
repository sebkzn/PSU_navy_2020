/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"

typedef struct boat_s {
    size_t length;
    char *front;
    char *back;
} boat_t;

typedef struct status_s {
    int received;
    pid_t pid;
    int hit;
    int won;
    int count;
} status_t;

extern status_t statusinfo;

boat_t **get_positions(char const *filename);
boat_t **fill_boat_array(char const *filename);
void create_game(boat_t **boats);
void connect_game(pid_t pid, boat_t **boats);
void display_board(char **board, int enemy);
char **create_board(boat_t **boats);
int get_input(pid_t enemypid, char ***enemy_board);
int receive_attack(pid_t enemypid, char ***board);
void is_hit(int sig);
void atk_pos(int sig);
void destruct_game(boat_t **boat_array);

#endif /* !NAVY_H_ */
