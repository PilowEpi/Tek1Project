/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init effects
*/

#include <stdlib.h>

#include "rpg.h"

void init_renderstate(sfRenderStates *state, sfShader *shader)
{
    state->blendMode = sfBlendAlpha;
    state->shader = shader;
    state->transform = sfTransform_Identity;
    state->texture = NULL;
}

void init_effects(globals_t *gl)
{
    gl->effects = malloc(sizeof(effects_t));
    gl->effects->ennemy_sh = sfShader_createFromFile(
        "assets/shaders/simple.vert", 0, "assets/shaders/water1.frag");
    gl->effects->fog_sh = sfShader_createFromFile(
        "assets/shaders/simple.vert", 0, "assets/shaders/fog.frag");
    sfShader_setVec2Uniform(gl->effects->ennemy_sh, "u_resolution",
        (sfGlslVec2) {gl->mode.width, gl->mode.height});
    sfShader_setVec2Uniform(gl->effects->fog_sh, "u_resolution",
        (sfGlslVec2) {gl->mode.width, gl->mode.height});
    gl->effects->ennemy_rs = malloc(sizeof(sfRenderStates));
    gl->effects->fog_rs = malloc(sizeof(sfRenderStates));
    init_renderstate(gl->effects->ennemy_rs, gl->effects->ennemy_sh);
    init_renderstate(gl->effects->fog_rs, gl->effects->fog_sh);
    gl->effects->main_fog = sfTexture_create(gl->mode.width, gl->mode.height);
    gl->effects->fog = sfSprite_create();
    sfSprite_setTexture(gl->effects->fog, gl->effects->main_fog, sfTrue);
}
