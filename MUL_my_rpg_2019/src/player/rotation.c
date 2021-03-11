/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Allow player to rotate (focus mouse)
*/

#include <stdlib.h>

#include "rpg.h"
#include "engine.h"

void mouse_move_event(sfEvent *event,
    entity_t *player, globals_t *gl, sfRenderWindow *window)
{
    sfVector2f mouse = (sfVector2f) {event->mouseMove.x, event->mouseMove.y};
    sfVector2f mouse_i = sfRenderWindow_mapPixelToCoords(window,
        (sfVector2i) {mouse.x, mouse.y}, gl->main_view);
    float angle = 0;
    float old_angle = sfConvexShape_getRotation(player->body[0]);

    mouse = (sfVector2f) {mouse_i.x, mouse_i.y};
    angle = get_angle(player->pos, mouse);
    for (int i = 0; player->body[i]; i++) {
        sfConvexShape_setRotation(player->body[i], angle);
        if (!is_newpos_colliding_walls(player->body[i],
            gl->rooms[gl->room_index]->walls))
            continue;
        for (int y = 0; player->body[y]; y++) {
            sfConvexShape_setRotation(player->body[y], old_angle);
        }
        return;
    }
}