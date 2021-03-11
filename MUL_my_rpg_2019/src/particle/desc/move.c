/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** System movements description
*/

#include <stdlib.h>

#include "particle.h"
#include "my.h"

void clean_mv_desc(descriptor_t *desc)
{
    free(desc->org);
    free(desc->dir);
    desc->dir = 0;
    desc->org = 0;
    desc->org_size = -1;
    desc->dir_size = -1;
    desc->reg_rect = (sfIntRect) {-1, -1, -1, -1};
}

void desc_set_region_square(descriptor_t *desc, sfIntRect rect, char dir)
{
    clean_mv_desc(desc);
    desc->flags |= dir | (1 << 2);
    desc->reg_rect = rect;
}

void desc_set_region_point(descriptor_t *desc, sfVector2f pt, char dir)
{
    desc_set_region_square(desc, (sfIntRect) {pt.x, pt.y, 1, 1}, dir);
}
