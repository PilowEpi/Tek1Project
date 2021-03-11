/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_game
*/

#include <stdlib.h>

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int init_anim(glo_t *gl)
{
    gl->anim_clock = sfClock_create();
    gl->pos_x = 0;
    gl->pos_y = 0;
    gl->anim = sfSprite_create();
    gl->anim_tex = sfTexture_createFromFile("assets/anim.png", 0);
    if (!gl->anim_tex || !gl->anim_clock || !gl->anim)
        return (84);
    sfSprite_setTexture(gl->anim, gl->anim_tex, sfTrue);
    sfSprite_setTextureRect(gl->anim, (sfIntRect) {0, 0, 500, 500});
    sfSprite_setPosition(gl->anim, (sfVector2f) {
        (gl->win.width - 500) / 2, (gl->win.height - 500) / 2});
    gl->counter = 0;
    return (0);
}

int init_game(glo_t *gl)
{
    int nb_scene = 0;
    int ret = 0;

    init_anim(gl);
    for (; data_scene[nb_scene].type_scene != LAST; nb_scene++);
    gl->scenes = malloc(sizeof(scene_t) * nb_scene);
    gl->nb_scene = nb_scene;
    if (gl->scenes == NULL)
        return (84);
    for (int i = 0; i < nb_scene; i++) {
        initialize_scene(&gl->scenes[i], &ret, data_scene[i]);
        if (ret == 84)
            return (84);
    }
    return (0);
}
