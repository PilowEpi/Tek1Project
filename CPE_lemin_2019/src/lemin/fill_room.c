/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** fill_room
*/

#include <stdlib.h>

#include "my.h"
#include "lemin.h"

int fill_nb_ant(lemin_t *lemin)
{
    lemin->nb_ant = my_getnbr(lemin->list->info_line);
    if (lemin->nb_ant == 0) {
        return (84);
    }
    return (0);
}

int get_nb_room(lemin_t *lemin)
{
    int room = 0;
    info_t *tmp = lemin->list;

    for (; tmp; tmp = tmp->next) {
        if (is_room(tmp->info_line) == 1)
            room++;
        else if (is_pipe(tmp->info_line) == 1)
            break;
    }
    return (room);
}

int fill_data(lemin_t *lemin)
{
    info_t *tmp = lemin->list;
    int counter = 0;

    for (; tmp; tmp = tmp->next) {
        if (is_room(tmp->info_line) == 1) {
            add_room_in_data(tmp, lemin->data, counter);
            counter++;
        } else if (is_pipe(tmp->info_line) == 1) {
            break;
        }
    }
    return (0);
}

int fill_room(lemin_t *lemin)
{
    if (fill_nb_ant(lemin) == 84)
        return (84);
    lemin->data = malloc(sizeof(data_t) * get_nb_room(lemin));
    if (!lemin->data)
        return (84);
    fill_data(lemin);
    return (0);
}