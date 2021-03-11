/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** particle engine
*/

#include <stdlib.h>

#include "my.h"
#include "rpg.h"

void init_shader(part_t *engine, sfVideoMode mode)
{
    engine->shader = sfShader_createFromFile("assets/shaders/simple.vert", 0,
        "assets/shaders/particle.frag");
    engine->state = malloc(sizeof(sfRenderStates));
    engine->state->blendMode = sfBlendAlpha;
    engine->state->shader = engine->shader;
    engine->state->transform = sfTransform_Identity;
    engine->state->texture = NULL;
    sfShader_setVec2Uniform(engine->shader, "u_resolution",
        (sfGlslVec2) {mode.width, mode.height});
}

part_t *create_engine(sfVideoMode mode)
{
    part_t *engine = malloc(sizeof(part_t));

    if (!engine)
        return (0);
    engine->systems = malloc(sizeof(syst_t *));
    if (!engine->systems)
        return (0);
    engine->systems[0] = 0;
    init_shader(engine, mode);
    return (engine);
}

void update_engine(part_t *engine, double delta)
{
    for (int i = 0; engine->systems[i] != 0; i++){
        if (engine->systems[i]->desc->duration == -1)
            continue;
        engine->systems[i]->desc->duration -= delta;
        if (engine->systems[i]->desc->duration < 0){
            remove_system(engine, engine->systems[i]);
            i = 0;
        }
    }
}

void append_system(part_t *engine, syst_t *system)
{
    int sys_len = 0;

    if (!engine || !system)
        return;
    if (engine->systems)
        for (; engine->systems[sys_len] != 0; sys_len++);
    engine->systems = my_realloc(engine->systems,
        sizeof(syst_t *) * (sys_len + 1), sizeof(syst_t *) * (sys_len + 2));
    engine->systems[sys_len] = system;
    engine->systems[sys_len + 1] = 0;
}

void remove_system(part_t *engine, syst_t *system)
{
    syst_t **syst = engine->systems;
    int ec = 0;
    int index = 0;

    for (; syst[ec]; ec++);
    for (int i = 0; i < ec; i++)
        if (syst[i] != system)
            syst[index++] = syst[i];
    syst[index] = 0;
    free(system);
}
