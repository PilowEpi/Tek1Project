/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** check_no_room
*/

#include "my.h"
#include "lemin.h"

int check_no_room(lemin_t *lemin)
{
    int counter = 0;
    info_t *tmp = lemin->list;

    for (; tmp; tmp = tmp->next) {
        if (is_room(tmp->info_line) == 1)
            counter++;
    }
    if (counter == 0)
        return (84);
    return (0);
}