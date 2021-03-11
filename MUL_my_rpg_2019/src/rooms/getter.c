/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Allow Player to move
*/

#include <stdlib.h>

#include "rpg.h"

info_t *get_room_start(room_t *room)
{
    for (int i = 0; room->info && room->info[i]; i++) {
        if (room->info[i]->type == 0)
            return (room->info[i]);
    }
    return (0);
}

info_t *get_room_end(room_t *room)
{
    for (int i = 0; room->info && room->info[i]; i++) {
        if (room->info[i]->type == 1)
            return (room->info[i]);
    }
    return (0);
}