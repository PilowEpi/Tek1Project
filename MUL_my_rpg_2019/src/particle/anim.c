/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** particle engine animation
*/

#include <math.h>

#include "particle.h"

void animate_particle(point_t *particle, double delta)
{
    particle->pos.x += particle->vel.x * delta;
    particle->pos.y += particle->vel.y * delta;
    particle->life += delta;
}

void draw_point(syst_t *syst, point_t *pt,
    sfRenderWindow *window, sfRenderStates *state, sfView *view)
{
    int size = syst->desc->size[0];
    sfColor c = syst->desc->color[0];
    sfVector2i p = sfRenderWindow_mapCoordsToPixel(window, pt->pos, view);

    sfSprite_setScale(syst->sprite, (sfVector2f) {4 * size, 4 * size});
    sfSprite_setPosition(syst->sprite, (sfVector2f)
        {pt->pos.x - 2 * size, pt->pos.y - 2 * size});
    sfShader_setVec2Uniform((sfShader *)state->shader,
        "u_pos", (sfGlslVec2) {p.x, p.y});
    sfShader_setVec3Uniform((sfShader *)state->shader,
        "u_color", (sfGlslVec3) {c.r, c.g, c.b});
    sfShader_setIntUniform((sfShader *)state->shader, "u_size", size);
    sfRenderWindow_drawSprite(window, syst->sprite, state);
}

void animate_system(syst_t *system, double delta,
    sfRenderWindow *window, sfRenderStates *state, sfView *view)
{
    descriptor_t *desc = system->desc;

    if (system->timer <= 0){
        append_particle(system, create_particle(desc));
        system->timer = desc->lifetime / desc->qty;
    }
    system->timer -= delta;
    for (point_t *pt = system->pt_head; pt != 0; pt = pt->next){
        animate_particle(pt, delta);
        draw_point(system, pt, window, state, view);
    }
    for (point_t *pt = system->pt_head; pt != 0; pt = pt->next){
        if (pt->life > desc->lifetime){
            delete_particle(system, pt);
            pt = system->pt_head;
        }
        if (pt == 0)
            break;
    }
}

void animate_engine(
    part_t *engine, double delta, sfRenderWindow *window, sfView *view)
{
    for (int i = 0; engine->systems[i] != 0; i++)
        animate_system(engine->systems[i], delta, window, engine->state, view);
    update_engine(engine, delta);
}
