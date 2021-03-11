/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** pathfinding
*/

#include "lemin.h"

int get_next_move(int pos, room_t **anthill)
{
    int end_id = 0;

    for (; anthill[end_id]->type != END; end_id++);
    return (end_id);
}
