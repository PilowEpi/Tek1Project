/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** more
*/

#include "rpg.h"

int more_armor(void *data)
{
    glo_t *glo = (glo_t *) data;
    globals_t *gl = glo->data;

    gl->hud->max_armor *= 2;
    return (0);
}

int more_speed(void *data)
{
    return (0);
}

int more_dmg(void *data)
{
    glo_t *glo = (glo_t *) data;
    globals_t *gl = glo->data;

    for (int i = 0; gl->player->weapon_list[i]; i++) {
        gl->player->weapon_list[i]->damage *= 2;
    }
    return (0);
}

int swap_to_tuto(void *data)
{
    ((glo_t *)data)->curr_scene = HOW_TO;
    return (0);
}