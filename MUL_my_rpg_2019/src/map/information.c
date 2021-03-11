/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch map read info
*/

#include <stdlib.h>

#include "rpg.h"

info_t *init_new_info(sfVector2f pos, char type, char id)
{
    info_t *info = malloc(sizeof(info_t));

    if (!info)
        return (info);
    info->pos = pos;
    info->type = type;
    if (type == 2)
        info->id_obj = id;
    return (info);
}

int add_info_to_room(room_t *room, char type, sfVector2f pos, char id)
{
    int ic = 0;
    info_t **new_info;

    for (ic = 0; room->info && room->info[ic]; ic++);
    new_info = malloc(sizeof(info_t *) * (ic + 2));
    if (!new_info)
        return (1);
    for (int i = 0; i < ic; i++)
        new_info[i] = room->info[i];
    new_info[ic] = init_new_info(pos, type, id);
    new_info[ic + 1] = 0;
    if (!new_info[ic])
        return (1);
    if (room->info)
        free(room->info);
    room->info = new_info;
    return (0);
}

int add_info(dfile_t *a_data, room_t *room, int *i)
{
    unsigned char *data = a_data->data;
    short pos[2];
    char type;
    char id;
    sfVector2f posi = (sfVector2f) {0, 0};

    data = data + *i;
    if (a_data->data_size < *i + 5)
        return (-(a_data->data_size));
    type = data[1];
    pos[0] = data[2] << 8;
    pos[0] |= data[3];
    pos[1] = data[4] << 8;
    pos[1] |= data[5];
    if (type == 2)
        id = data[6];
    posi = (sfVector2f) {(float) pos[0], (float) pos[1]};
    if (add_info_to_room(room, type, posi, id))
        return (-(a_data->data_size));
    return (type == 2 ? 7 : 6);
}