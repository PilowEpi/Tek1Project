/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Lauch reading item bodies
*/

#include <stdlib.h>

#include "rpg.h"

sfConvexShape *init_new_body(short *points, char point_count, char color_d[4])
{
    sfConvexShape *body = sfConvexShape_create();
    sfVector2f point;
    int p_i = 0;
    sfColor color;

    if (!body)
        return (body);
    sfConvexShape_setPointCount(body, point_count);
    for (int i = 0; i < point_count; i++) {
        point = (sfVector2f) {(float) points[p_i++], (float) points[p_i++]};
        sfConvexShape_setPoint(body, i, point);
    }
    color = sfColor_fromRGBA(color_d[0], color_d[1], color_d[2], color_d[3]);
    sfConvexShape_setFillColor(body, color);
    return (body);
}

int add_body_to_it(loot_t *item, short *points, char nb_points, char color[4])
{
    int lc = 0;
    sfConvexShape **new_body;

    for (lc = 0; item->body && item->body[lc]; lc++);
    new_body = malloc(sizeof(sfConvexShape *) * (lc + 2));
    if (!new_body)
        return (1);
    for (int i = 0; i < lc; i++)
        new_body[i] = item->body[i];
    new_body[lc] = init_new_body(points, nb_points, color);
    new_body[lc + 1] = 0;
    if (!new_body[lc])
        return (1);
    if (item->body)
        free(item->body);
    item->body = new_body;
    return (0);
}

int add_body_to_item(dfile_t *a_data, loot_t *item, int *i, int j)
{
    unsigned char *data = a_data->data;
    char nb_points = data[*i + 1];
    unsigned char color[4];
    int index = 0;
    short *points = malloc(sizeof(short) * (nb_points * 2));

    data = data + *i;
    if (a_data->data_size < *i + (nb_points * 4) || !points)
        return (-(a_data->data_size));
    for (j = 2; j < (nb_points * 4) + 1; j += 2) {
        points[index] = data[j] << 8;
        points[index++] |= data[j + 1];
    }
    color[0] = data[j++];
    color[1] = data[j++];
    color[2] = data[j++];
    color[3] = data[j];
    if (add_body_to_it(item, points, nb_points, color))
        return (-(a_data->data_size));
    return (nb_points * 4 + 6);
}