/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Init assets
*/

#include <stdio.h>
#include <stdlib.h>

#include "rpg.h"
#include "engine.h"
#include "my.h"

void init_state(globals_t *gl)
{
    gl->state = malloc(sizeof(sfRenderStates));
    gl->state->blendMode = sfBlendAlpha;
    gl->state->shader = gl->shader;
    gl->state->transform = sfTransform_Identity;
    gl->state->texture = NULL;
}

void init_views(globals_t *gl)
{
    gl->main_view = sfView_create();
    gl->hud_view = sfView_create();
    sfView_setSize(gl->main_view, (sfVector2f) {1920, 1080});
    sfView_setSize(gl->hud_view, (sfVector2f) {1920, 1080});
    sfView_setCenter(gl->hud_view,
        (sfVector2f) {gl->mode.width / 2, gl->mode.height / 2});
    sfView_setCenter(gl->main_view, gl->player->pos);
}

void init_room_object(room_t *room, globals_t *gl)
{
    loot_t *object;

    for (int i = 0; room->info[i]; i++) {
        if (room->info[i]->type != 2)
            continue;
        add_item_to_word(gl, room->info[i]->id_obj, room->info[i]->pos);
    }
}

void init_object(globals_t *gl)
{
    room_t **rooms = gl->rooms;

    for (int i = 0; rooms && rooms[i]; ++i) {
        init_room_object(rooms[i], gl);
    }
}

void init_main(globals_t *gl)
{
    gl->mode = (sfVideoMode) {1920, 1080, 32};
    gl->shader = sfShader_createFromFile("assets/shaders/simple.vert", 0,
        "assets/shaders/light.frag");
    init_state(gl);
    gl->clock = sfClock_create();
    sfShader_setVec2Uniform(gl->shader, "u_resolution",
        (sfGlslVec2) {gl->mode.width, gl->mode.height});
    gl->clock = sfClock_create();
    init_engine(gl);
    init_lights_at_room(gl, 0);
    init_views(gl);
    init_hud(gl);
    init_object(gl);
    init_effects(gl);
    gl->particle = create_engine(gl->mode);
    update_ends(gl);
}
