/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event handling
*/

#include <stdlib.h>

#include "rpg.h"

void give_weapong(globals_t *gl, loot_t *item)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->type = 1;
    weapon->clock = sfClock_create();
    weapon->cooldown = 0.5;
    weapon->damage = 100;
    weapon->range = 40;
    add_weapon_to_entity(gl->player, weapon);
    remove_item_from_word(gl, item);
}

int pickup_to_inv(globals_t *gl, int i)
{
    for (int y = 0; y < SLOT_NB; y++) {
        if (!gl->hud->inv_contains[y]) {
            gl->hud->inv_contains[y] =
                copy_item(gl, gl->rooms[gl->room_index]->items[i]->id);
            remove_item_from_word(gl, gl->rooms[gl->room_index]->items[i]);
            return (1);
        }
    }
    return (0);
}

void pickup_obj(globals_t *gl, sfEvent *event)
{
    float distance = 0;
    sfVector2f pos;

    if (event->key.code != sfKeyA)
        return;
    for (int i = 0; gl->rooms[gl->room_index]->items[i]; i++) {
        pos = sfConvexShape_getPosition(
            gl->rooms[gl->room_index]->items[i]->body[0]);
        distance = get_distance(gl->player->pos, pos);
        if (distance > 100)
            continue;
        if (gl->rooms[gl->room_index]->items[i]->id == 2) {
            give_weapong(gl, gl->rooms[gl->room_index]->items[i]);
            return;
        }
        if (pickup_to_inv(gl, i))
            return;
    }
}

void swap_scene_event(sfEvent *event, globals_t *gl)
{
    if (event->key.code == sfKeyS) {
        swap_to_skill(gl->data);
    } else if (event->key.code == sfKeyEscape) {
        swap_to_pause(gl->data);
    }
}

void handle_main_event(sfRenderWindow *window, sfEvent *event, globals_t *gl)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event->type == sfEvtKeyPressed) {
        move_player_event(window, event, gl);
        if (!gl->rooms[gl->room_index]->enemies[0]) {
            show_swap_room_key(window, gl);
            swap_room_event(event, gl);
        }
        pickup_obj(gl, event);
        attack_event(window, gl, event);
        consume_item(gl, event);
        swap_scene_event(event, gl);
    }
    if (event->type == sfEvtMouseMoved)
        mouse_move_event(event, gl->player, gl, window);
}
