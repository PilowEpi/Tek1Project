/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Particle handling
*/

#include <stdlib.h>
#include <math.h>

#include "particle.h"

void part_mod_vel(point_t *part, descriptor_t *desc, char dir)
{
    switch (dir){
    case DIR_DOWN:
        part->vel.y += desc->speed[0];
        break;
    case DIR_UP:
        part->vel.y -= desc->speed[0];
        break;
    case DIR_LEFT:
        part->vel.x -= desc->speed[0];
        break;
    case DIR_RIGHT:
        part->vel.x += desc->speed[0];
        break;
    }
}

void set_part_pos(point_t *part, descriptor_t *desc)
{
    int start_idx = desc->org_size <= 0 ? -1 : rand() % desc->org_size;
    int width = desc->reg_rect.width == 0 ? 1 : desc->reg_rect.width;
    int height = desc->reg_rect.height == 0 ? 1 : desc->reg_rect.height;
    int x = desc->reg_rect.left + (rand() % width);
    int y = desc->reg_rect.top + (rand() % height);

    if (start_idx < 0)
        part->pos = (sfVector2f) {x, y};
    else
        part->pos = desc->org[start_idx];
}

void part_vel_rand(point_t *part, descriptor_t *desc)
{
    double gen = (double) (rand() % 628) / 100;

    part->vel.x = cos(gen) * desc->speed[0];
    part->vel.y = sin(gen) * desc->speed[0];
}

point_t *create_particle(descriptor_t *desc)
{
    point_t *part = malloc(sizeof(point_t));

    if (!part || !desc)
        return (0);
    part->next = 0;
    part->prev = 0;
    part->life = 0;
    part->color = desc->color[0];
    set_part_pos(part, desc);
    part->vel = (sfVector2f){0, 0};
    if (desc->flags & 0x4)
        part_mod_vel(part, desc, desc->flags & 0x3);
    if (desc->flags & DIR_RANDOM)
        part_vel_rand(part, desc);
    return (part);
}
