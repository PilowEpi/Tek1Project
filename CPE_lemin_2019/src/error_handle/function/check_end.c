/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_end
*/

#include "lemin.h"
#include "my.h"

int count_end(lemin_t *lemin)
{
    int end_points = 0;

    for (int i = 0; lemin->anthill[i]; i++){
        if (lemin->anthill[i]->type == END)
            end_points++;
    }
    return (end_points);
}

int check_final_end(lemin_t *lemin)
{
    int end_points = 0;

    for (int i = 0; lemin->anthill[i]; i++){
        if (lemin->anthill[i]->type == END)
            end_points++;
    }
    if (end_points != 1)
        return (84);
    return (0);
}