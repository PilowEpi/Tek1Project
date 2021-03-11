/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** raycast
*/

#include "rpg.h"
#include "particle.h"
#include "engine.h"
#include "my.h"

float get_distance(sfVector2f, sfVector2f);

int is_on_end(globals_t *gl)
{
    entity_t *player = gl->player;
    info_t *end_point = get_room_end(gl->rooms[gl->room_index]);

    if (get_distance(player->pos, end_point->pos) <= 100)
        return (1);
    return (0);
}

void update_ends(globals_t *gl)
{
    info_t *end = get_room_end(gl->rooms[gl->room_index]);
    syst_t *new = create_system();

    while (gl->particle->systems[0] != 0)
        remove_system(gl->particle, gl->particle->systems[0]);
    desc_set_region_point(new->desc, end->pos, DIR_RANDOM);
    new->desc->size[0] = 40;
    new->desc->speed[0] = 50;
    new->desc->lifetime = 2;
    new->desc->qty = 20;
    append_system(gl->particle, new);
}

void swap_room_event(sfEvent *event, globals_t *gl)
{
    info_t *end;
    if (is_on_end(gl) && event->type == sfEvtKeyPressed
        && event->key.code == sfKeyE) {
        gl->room_index = gl->room_index + 1;
        if (!gl->rooms[gl->room_index])
            swap_to_end(gl->data);
        end = get_room_start(gl->rooms[gl->room_index]);
        gl->player->pos = end->pos;
        free_polygones(gl->light_polys);
        gl->light_polys = alloc_polygones(gl->rooms[gl->room_index]);
        update_lights(gl->light_polys, gl);
        update_ends(gl);
    }
}

void show_swap_room_key(sfRenderWindow *window, globals_t *gl)
{
    info_t *end_point = get_room_end(gl->rooms[gl->room_index]);

    if (!is_on_end(gl))
        return;
    if (!end_point) {
        my_printf("No endpoint in the room !\n");
        return;
    }
    sfText_setPosition(gl->end_room, end_point->pos);
}
