/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Draw loop
*/

#include "rpg.h"

void enemy_attack(globals_t *gl)
{
    entity_t **enemies = gl->rooms[gl->room_index]->enemies;

    for (int i = 0; enemies && enemies[i]; i++) {
        if (get_distance(enemies[i]->pos, gl->player->pos) <
            enemies[i]->weapon_list[0]->range)
            use_weapon(enemies[i], enemies[i]->weapon_list[0],
                gl->player->pos, gl);
    }
}

void game_loop(sfRenderWindow *window, globals_t *gl)
{
    sfTime time = sfClock_getElapsedTime(gl->clock);
    sfInt32 i_time = sfTime_asMicroseconds(time);
    double f_time = ((double) i_time) / 100;

    move_bullet(gl);
    update_light_position(window, gl);
    update_enemies_pos(gl);
    enemy_attack(gl);
    sfRenderWindow_clear(window, sfBlack);
    draw_mainview(window, gl);
    draw_hudview(window, gl, f_time);
}
