/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_start
*/

#include "lemin.h"
#include "my.h"

int check_final(lemin_t *lemin)
{
    int start_points = 0;
    int end_points = 0;

    for (int i = 0; lemin->anthill[i]; i++){
        if (lemin->anthill[i]->type == START)
            start_points++;
        if (lemin->anthill[i]->type == END)
            end_points++;
    }
    if (start_points != 1 || end_points != 1)
        return (84);
    return (0);
}