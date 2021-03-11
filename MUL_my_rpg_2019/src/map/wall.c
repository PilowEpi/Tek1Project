/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch map read walls
*/

#include <stdlib.h>

#include "rpg.h"

sfConvexShape *init_new_wall(short *points, int pc)
{
    sfConvexShape *shape = sfConvexShape_create();
    int p_i = 0;
    sfVector2f point;

    if (!shape)
        return (shape);
    sfConvexShape_setPointCount(shape, pc);
    for (int i = 0; i < pc; i++) {
        point = (sfVector2f) {(float) points[p_i++], (float) points[p_i++]};
        sfConvexShape_setPoint(shape, i, point);
    }
    sfConvexShape_setFillColor(shape, sfBlack);
    return (shape);
}

int add_wall_to_room(room_t *room, short *points, int point_count)
{
    int wc = 0;
    sfConvexShape **new_walls;

    for (; room->walls && room->walls[wc]; wc++);
    new_walls = malloc(sizeof(sfConvexShape *) * (wc + 2));
    if (!new_walls)
        return (1);
    for (int i = 0; i < wc; i++)
        new_walls[i] = room->walls[i];
    new_walls[wc] = init_new_wall(points, point_count);
    new_walls[wc + 1] = 0;
    if (!new_walls[wc])
        return (1);
    room->walls = new_walls;
    return (0);
}

int add_wall(dfile_t *a_data, room_t *room, int *i)
{
    unsigned char *data = a_data->data;
    char nb_points = data[*i + 1];
    int index = 0;
    short *points = malloc(sizeof(short) * (nb_points * 2));

    data = data + *i;
    if (a_data->data_size < *i + (nb_points * 2) || !points)
        return (-(a_data->data_size));
    for (int j = 2; j < (nb_points * 4) + 1; j += 2) {
        points[index] = data[j] << 8;
        points[index++] |= data[j + 1];
    }
    if (add_wall_to_room(room, points, nb_points))
        return (-(a_data->data_size));
    return ((nb_points * 4) + 2);
}