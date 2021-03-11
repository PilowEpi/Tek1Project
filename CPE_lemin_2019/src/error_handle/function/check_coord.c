/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_coord
*/

#include "my.h"
#include "lemin.h"

int check_same_data(int i, int j, room_t **anthill)
{
    if (i != j &&
        anthill[i]->x == anthill[j]->x &&
        anthill[i]->y == anthill[j]->y)
        return (1);
    return (0);
}

int check_coord(lemin_t *lemin)
{
    int error = 0;

    for (int i = 0; lemin->anthill[i] != 0; i++) {
        for (int j = 0; lemin->anthill[j] != 0; j++) {
            error += check_same_data(i, j, lemin->anthill);
        }
    }
    if (error != 0) {
        return (-1);
    }
    return (0);
}