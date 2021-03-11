/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Draw loop
*/

#include "rpg.h"

void draw_walls(sfRenderWindow *window, globals_t *gl)
{
    room_t *room = gl->rooms[gl->room_index];

    for (int i = 0; room->walls && room->walls[i]; i++)
        sfRenderWindow_drawConvexShape(window, room->walls[i], 0);
}

void draw_lights(sfRenderWindow *window, globals_t *gl)
{
    for (int i = 0; gl->light_polys[i] != 0; i++){
        for (int j = 0; gl->light_polys[i][j] != 0; j++){
            sfRenderWindow_drawConvexShape(
                window, gl->light_polys[i][j], gl->state);
        }
    }
}

void update_light_position(sfRenderWindow *window, globals_t *gl)
{
    room_t *room = gl->rooms[gl->room_index];
    sfGlslVec3 *lights = gl->light_shader_obj;
    int lc = 0;
    sfVector2i new_pos;

    while (room->lights && room->lights[lc] != 0)
        lc++;
    for (int i = 0; i < lc; i++) {
        new_pos =
            sfRenderWindow_mapCoordsToPixel(window,
            gl->rooms[gl->room_index]->lights[i]->position, gl->main_view);
        lights[i] = (sfGlslVec3) {new_pos.x, new_pos.y, lights[i].z};
    }
    sfShader_setVec3UniformArray(gl->shader, "u_lights", lights, lc);
}

void draw_inv(sfRenderWindow *window, globals_t *gl)
{
    sfVideoMode mode = gl->mode;

    for (int i = 0; i < SLOT_NB * 2; i++)
        sfRenderWindow_drawConvexShape(window, gl->hud->inv_slots[i], 0);
    for (int i = 0; i < SLOT_NB; i++) {
        if (!gl->hud->inv_contains[i])
            continue;
        for (int y = 0; gl->hud->inv_contains[i]->body[y]; y++) {
            sfConvexShape_setPosition(
                gl->hud->inv_contains[i]->body[y],
                (sfVector2f) {(mode.width - SLOT_NB * (50 + INV_MARGIN))
            / 2 + (i * (50 + INV_MARGIN)), mode.height - 120});
            sfRenderWindow_drawConvexShape(
                window, gl->hud->inv_contains[i]->body[y], 0);
        }
    }
}

void draw_hud(sfRenderWindow *window, globals_t *gl)
{
    draw_inv(window, gl);
    sfRenderWindow_drawConvexShape(window, gl->hud->l_container, 0);
    sfRenderWindow_drawConvexShape(window, gl->hud->life_bar, 0);
    sfRenderWindow_drawConvexShape(window, gl->hud->x_container, 0);
    sfRenderWindow_drawConvexShape(window, gl->hud->xp_bar, 0);
    sfRenderWindow_drawConvexShape(window, gl->hud->armor_bar, 0);
    sfRenderWindow_drawSprite(window, gl->effects->fog, gl->effects->fog_rs);
    sfRenderWindow_drawText(window, gl->quest, 0);
    if (!gl->rooms[gl->room_index]->enemies[0])
        sfRenderWindow_drawText(window, gl->hud->text_level, 0);
}
