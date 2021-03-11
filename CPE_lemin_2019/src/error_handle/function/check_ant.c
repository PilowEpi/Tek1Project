/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_ant
*/

#include "my.h"
#include "lemin.h"

int check_ant(lemin_t *lemin)
{
    info_t *nb_ant = lemin->list;

    for (int i = 0; nb_ant->info_line[i]; i++) {
        if (!is_num(nb_ant->info_line[i]))
            return (84);
    }
    return (0);
}