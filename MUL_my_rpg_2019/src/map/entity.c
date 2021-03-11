/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch map read entity
*/

#include <stdlib.h>

#include "rpg.h"

int add_enemy_to_room(room_t *room, sfVector2f pos, char info[3], dfile_t *data)
{
    int lc = 0;
    entity_t **new_enemy;

    for (; room->enemies && room->enemies[lc]; lc++);
    new_enemy = malloc(sizeof(entity_t *) * (lc + 2));
    if (!new_enemy)
        return (1);
    for (int i = 0; i < lc; i++)
        new_enemy[i] = room->enemies[i];
    new_enemy[lc] = init_new_enemy(data, pos, info);
    new_enemy[lc + 1] = 0;
    if (!new_enemy[lc])
        return (1);
    if (room->enemies)
        free(room->enemies);
    room->enemies = new_enemy;
    return (0);
}

int add_npc_to_room(room_t *room, sfVector2f pos, char info[3], dfile_t *data)
{
    int lc = 0;
    entity_t **new_npc;

    for (int wc = 0; room->npc && room->npc[lc]; lc++);
    new_npc = malloc(sizeof(entity_t *) * (lc + 2));
    if (!new_npc)
        return (1);
    for (int i = 0; i < lc; i++)
        new_npc[i] = room->npc[i];
    new_npc[lc] = init_new_npc(data, pos, info);
    new_npc[lc + 1] = 0;
    if (!new_npc[lc])
        return (1);
    if (room->npc)
        free(room->npc);
    room->npc = new_npc;
    return (0);
}

int add_entity_to_room(
    room_t *room, sfVector2f pos, char info[3], dfile_t *data)
{
    if (info[0] == 0) {
        if (add_enemy_to_room(room, pos, info, data))
            return (1);
    } else {
        if (add_npc_to_room(room, pos, info, data))
            return (1);
    }
    return (0);
}

int add_entity(dfile_t *a_data, room_t *room, int *i)
{
    unsigned char *data = a_data->data;
    char info[3];
    short x;
    short y;
    sfVector2f pos;

    data = data + *i;
    if (a_data->data_size < *i + 8)
        return (-(a_data->data_size));
    info[0] = data[1];
    x = data[2] << 8;
    x |= data[3];
    y = data[4] << 8;
    y |= data[5];
    info[1] = data[6];
    info[2] = data[7];
    pos = (sfVector2f) {(float) x, (float) y};
    if (add_entity_to_room(room, pos, info, a_data))
        return (-(a_data->data_size));
    return (8);
}