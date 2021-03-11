/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_destroy
*/

#include <stdlib.h>

#include "rpg.h"
#include "rpg_struct.h"
#include "my.h"

int destroy_sprite(scene_t *scene)
{
    for (int i = 0; i < scene->nb_sprite ; i++) {
        sfSprite_destroy(scene->sprite[i].img);
        sfTexture_destroy(scene->sprite[i].texture);
    }
    free(scene->sprite);
    return (0);
}

int destroy_button(scene_t *scene)
{
    for (int i = 0; i < scene->nb_button ;i++) {
        sfSprite_destroy(scene->button[i].b_sprite.img);
        sfTexture_destroy(scene->button[i].b_sprite.texture);
    }
    free(scene->button);
    return (0);
}

int destroy_scene(glo_t *gl)
{
    for (int i = 0; i < gl->nb_scene; i++) {
        destroy_sprite(&gl->scenes[i]);
        destroy_button(&gl->scenes[i]);
    }
    free(gl->scenes);
    return (0);
}

void destroy_clocks(clocks_t *clocks)
{
    sfClock_destroy(clocks->clock);
}

int clean_memory(glo_t *gl)
{
    sfRenderWindow_destroy(gl->win.window);
    destroy_clocks(&gl->main_clock);
    destroy_scene(gl);
    return (0);
}
