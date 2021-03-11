/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Draw loop
*/

#include "rpg.h"

void draw_enemies(sfRenderWindow *window, globals_t *gl)
{
    entity_t **enemies = gl->rooms[gl->room_index]->enemies;

    for (int i = 0; enemies && enemies[i]; i++) {
        for (int y = 0; enemies[i]->body && enemies[i]->body[y]; y++) {
            sfConvexShape_setPosition(enemies[i]->body[y], enemies[i]->pos);
            sfRenderWindow_drawConvexShape(window, enemies[i]->body[y], gl->effects->ennemy_rs);
        }
    }
}

void update_enemies_pos(globals_t *gl)
{
    for (int i = 0; gl->rooms[gl->room_index]->enemies[i]; i++) {
        move_enemy(gl->rooms[gl->room_index]->enemies[i], gl);
    }
}

void draw_items(sfRenderWindow *window, globals_t *gl)
{
    room_t *room = gl->rooms[gl->room_index];
    for (int i = 0; room->items && room->items[i]; i++) {
        for (int y = 0; room->items[i]->body && room->items[i]->body[y]; y++) {
            sfRenderWindow_drawConvexShape(window, room->items[i]->body[y], 0);
        }
    }
}

void draw_mainview(sfRenderWindow *window, globals_t *gl)
{
    sfTime time = sfClock_restart(gl->clock);
    double delta = (double) sfTime_asMilliseconds(time) / 1000;

    sfRenderWindow_setView(window, gl->main_view);
    draw_lights(window, gl);
    draw_walls(window, gl);
    draw_entity(window, gl->player);
    draw_enemies(window, gl);
    draw_items(window, gl);
    animate_engine(gl->particle, delta, window, gl->main_view);
    if (is_on_end(gl)) {
        sfRenderWindow_drawText(window, gl->end_room, 0);
    }
}

void draw_hudview(sfRenderWindow *window, globals_t *gl, double f_time)
{
    static double at;
    sfVector2i p = sfRenderWindow_mapCoordsToPixel(window,
        (sfVector2f) {0, 0}, gl->main_view);

    at += f_time;
    sfShader_setFloatUniform(gl->effects->fog_sh, "u_time", at);
    sfShader_setVec2Uniform(gl->effects->fog_sh, "u_pos",
        (sfGlslVec2) {(float) p.x, (float) p.y});
    sfRenderWindow_setView(window, gl->hud_view);
    draw_hud(window, gl);
}
