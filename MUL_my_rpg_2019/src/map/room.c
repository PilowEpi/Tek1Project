/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch map read rooms
*/

#include <stdlib.h>

#include "rpg.h"

void set_newrooms_null(room_t *room)
{
    room->walls = NULL;
    room->lights = NULL;
    room->info = NULL;
    room->enemies = NULL;
    room->npc = NULL;
    room->items = NULL;
}

void set_newrooms_data(room_t *room, dfile_t *data, int *i)
{
    unsigned short width;
    unsigned short height;
    short *rgb = malloc(sizeof(short) * 4);

    if (!rgb || *i + 9 > data->data_size)
        return;
    width = data->data[*i + 2] << 8;
    width |= data->data[*i + 3];
    height = data->data[*i + 4] << 8;
    height |= data->data[*i + 5];
    rgb[0] = data->data[*i + 6];
    rgb[1] = data->data[*i + 7];
    rgb[2] = data->data[*i + 8];
    rgb[3] = data->data[*i + 9];
    room->size = (sfVector2i) {(int) width, (int) height};
    room->color = sfColor_fromRGBA(rgb[0], rgb[1], rgb[2], rgb[3]);
    room->tex = sfTexture_create(room->size.x, room->size.y);
    set_newrooms_null(room);
}

int add_room(room_t ***rooms, int *size, dfile_t *data, int *i)
{
    room_t **new_rooms = malloc(sizeof(room_t *) * (*size + 2));
    room_t **old_rooms = *rooms;

    if (!new_rooms)
        return (1);
    for (int i = 0; i < *size; i++)
        new_rooms[i] = old_rooms[i];
    new_rooms[*size] = malloc(sizeof(room_t));
    new_rooms[*size + 1] = 0;
    if (!new_rooms[*size]) {
        free(new_rooms);
        return (1);
    }
    set_newrooms_data(new_rooms[*size], data, i);
    *size += 1;
    free(old_rooms);
    *rooms = new_rooms;
    return (0);
}