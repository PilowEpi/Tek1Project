/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Draw loop
*/

#include <stdlib.h>
#include <stdio.h>

#include "rpg.h"

void play_melee_attack(globals_t *gl, sfVector2f pos, sfColor color)
{
    syst_t *new = create_system();

    desc_set_region_point(new->desc, pos, DIR_RANDOM);
    new->desc->size[0] = 40;
    new->desc->speed[0] = 100;
    new->desc->duration = 1;
    new->desc->lifetime = 1;
    new->desc->qty = 20;
    new->desc->color = malloc(sizeof(sfColor));
    if (new->desc->color == NULL)
        return;
    new->desc->color[0] = color;
    append_system(gl->particle, new);
}

void use_melee_weapon(entity_t *entity,
    weapon_t *weapon, globals_t *gl)
{
    sfTime time = sfClock_getElapsedTime(weapon->clock);
    float seconds = sfTime_asSeconds(time);

    if (entity == gl->player && seconds >= weapon->cooldown) {
        player_melee_weapon(entity, weapon, gl);
        sfClock_restart(weapon->clock);
        return;
    }
    if (get_distance(entity->pos,
        gl->player->pos) < weapon->range && seconds >= weapon->cooldown) {
        if (update_life(gl->hud, -weapon->damage)) {
            make_lose(gl->data);
            swap_to_end((glo_t *) gl->data);
        }
        play_melee_attack(gl, gl->player->pos, sfRed);
        sfClock_restart(weapon->clock);
    }
}

void use_weapon(entity_t *entity,
    weapon_t *weapon, sfVector2f direction, globals_t *gl)
{
    if (weapon->type == DISTANCE)
        use_distance_weapon(entity, weapon, direction, gl);
    else
        use_melee_weapon(entity, weapon, gl);
}

int attack_event(sfRenderWindow *window, globals_t *gl, sfEvent *event)
{
    int i = 0;
    sfTime time;
    float elapsed;
    sfVector2i mouse_i = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse =
        sfRenderWindow_mapPixelToCoords(window, mouse_i, gl->main_view);

    if (!(event->type == sfEvtKeyPressed && event->key.code == sfKeySpace))
        return (1);
    for (; gl->player->weapon_list && gl->player->weapon_list[i]; i++) {
        time = sfClock_getElapsedTime(gl->player->weapon_list[i]->clock);
        elapsed = sfTime_asSeconds(time);
        if (elapsed < gl->player->weapon_list[i]->cooldown)
            continue;
        use_weapon(gl->player, gl->player->weapon_list[i], mouse, gl);
    }
    return (0);
}
