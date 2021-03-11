/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Descriptor creation
*/

#include <stdlib.h>

#include "particle.h"
#include "my.h"

descriptor_t *create_descriptor(void)
{
    descriptor_t *desc = malloc(sizeof(descriptor_t));

    if (!desc)
        return (0);
    desc->color = 0;
    desc->size = 0;
    desc->offset = 1;
    desc->speed = 0;
    desc->lifetime = 5;
    desc->duration = -1;
    desc->qty = 5;
    desc->flags = 0;
    desc->dir = 0;
    desc->org = 0;
    desc->id = 0;
    desc_append_color(desc, sfWhite);
    desc_append_size(desc, 10);
    desc_append_speed(desc, 1);
    desc_set_region_square(desc, (sfIntRect) {0, 0, 100, 0}, DIR_DOWN);
    return (desc);
}

void desc_append_color(descriptor_t *desc, sfColor color)
{
    int cur_size = 0;

    if (!desc)
        return;
    if (desc->color)
        for (; sfColor_toInteger(desc->color[cur_size]) != 0; cur_size++);
    desc->color = my_realloc(desc->color, sizeof(sfColor) * cur_size,
        sizeof(sfColor) * (cur_size + 2));
    desc->color[cur_size] = color;
    desc->color[cur_size + 1] = sfColor_fromInteger(0);
}

void desc_append_size(descriptor_t *desc, int n_size)
{
    int cur_size = 0;

    if (!desc)
        return;
    if (desc->size)
        for (; desc->size[cur_size] > 0; cur_size++);
    desc->size = my_realloc(desc->size, sizeof(int) * cur_size,
        sizeof(int) * (cur_size + 2));
    desc->size[cur_size] = n_size;
    desc->size[cur_size + 1] = -1;
}

void desc_append_speed(descriptor_t *desc, double n_speed)
{
    int cur_size = 0;

    if (!desc)
        return;
    if (desc->speed)
        for (; desc->speed[cur_size] > 0; cur_size++);
    desc->speed = my_realloc(desc->speed, sizeof(double) * cur_size,
        sizeof(double) * (cur_size + 2));
    desc->speed[cur_size] = n_speed;
    desc->speed[cur_size + 1] = -1;
}
