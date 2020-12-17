/*
** EPITECH PROJECT, 2020
** B-PSU-101-NCY-1-1-navy-sebastien.raoult
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include "my.h"

#define A (0)
#define B (1)
#define C (2)
#define D (3)
#define E (4)
#define F (5)
#define G (6)
#define H (7)

#define MIN(val1, val2) (val1 > val2 ? val2 : val1)

typedef struct boat_s {
    size_t length;
    char *front;
    char *back;
} boat_t;

typedef struct status_s {
    int received;
    pid_t pid;
    int sigone;
    int sigtwo;
} status_t;

extern status_t statusinfo;

boat_t **get_positions(char const *filename);
boat_t **fill_boat_array(char const *filename);
void create_game(boat_t **boats);
void connect_game(pid_t pid, boat_t **boats);
void display_board(char **board, int enemy);
char **create_board(boat_t **boats);

#endif /* !NAVY_H_ */
