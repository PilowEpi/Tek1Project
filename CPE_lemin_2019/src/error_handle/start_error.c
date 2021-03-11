/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** start_error
*/

#include "lemin.h"

int start_error(lemin_t *lemin)
{
    int (*error_fct[])(lemin_t *lemin) = {&check_final, &check_coord};

    for (int i = 0; i < 1; i++) {
        if (error_fct[i](lemin) == 84)
            return (84);
    }
    return (0);
}