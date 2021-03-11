/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** utils
*/

#include "rpg.h"

int more_healh(void *data)
{
    glo_t *glo = (glo_t *) data;
    globals_t *gl = glo->data;

    gl->hud->max_life *= 2;
    gl->hud->life = gl->hud->max_life;
    return (0);
}

int more_ligth(void *data)
{
    return (0);
}

int get_pistol(void *data)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));
    globals_t *gl = ((glo_t *) data)->data;

    weapon->type = DISTANCE;
    weapon->damage = 50;
    weapon->range = 300;
    weapon->cooldown = 0.5;
    weapon->clock = sfClock_create();
    add_weapon_to_entity(gl->player, weapon);
    return (0);
}