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

boat_t **get_positions(char const *filename);
boat_t **fill_boat_array(char const *filename);

#endif /* !NAVY_H_ */
