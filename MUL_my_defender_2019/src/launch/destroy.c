/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** destroy
*/

#include <stdlib.h>
#include "struct_defender.h"
#include "dico_defender.h"

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

int destroy_scene(game_t *game)
{
    for (int i = 0; i < game->nb_scene; i++) {
        destroy_sprite(&game->def_scene[i]);
        destroy_button(&game->def_scene[i]);
    }
    free(game->def_scene);
    return (0);
}

int destroy_level(window_t *win, game_t *game)
{
    if (game->level != NULL) {
        sfClock_destroy(game->level->level_clock);
        free(game->level);
    }
    return (0);
}

int destroy_defender(window_t *win, game_t *game)
{
    sfRenderWindow_destroy(win->window);
    sfClock_destroy(game->clock);
    destroy_scene(game);
    return (0);
}