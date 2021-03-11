/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** size_game
*/

#include "struct_defender.h"
#include "defender.h"

int swap_small_size(void *data, void *win, void *game)
{
    sfVector2u curr_size = sfRenderWindow_getSize(((window_t *)win)->window);
    float x_size = 0.5;
    float y_size = 0.5;

    curr_size.x *= x_size;
    curr_size.y *= y_size;
    ((window_t *)win)->win_size = curr_size;
    for (int i = 0; i < ((game_t *)game)->nb_scene; i++) {
        for (int j = 0; j < ((game_t *)game)->def_scene[i].nb_button; j++) {
            ((game_t *)game)->def_scene[i].button[j].rect.height *= y_size;
            ((game_t *)game)->def_scene[i].button[j].rect.width *= x_size;
            ((game_t *)game)->def_scene[i].button[j].rect.top *= y_size;
            ((game_t *)game)->def_scene[i].button[j].rect.left *= x_size;
        }
    }
    return (0);
}

int swap_big_size(void *data, void *win, void *game)
{
    sfVector2u curr_size = sfRenderWindow_getSize(((window_t *)win)->window);
    float x_size = 2;
    float y_size = 2;

    curr_size.x *= x_size;
    curr_size.y *= y_size;
    ((window_t *)win)->win_size = curr_size;
    for (int i = 0; i < ((game_t *)game)->nb_scene; i++) {
        for (int j = 0; j < ((game_t *)game)->def_scene[i].nb_button; j++) {
            ((game_t *)game)->def_scene[i].button[j].rect.height *= y_size;
            ((game_t *)game)->def_scene[i].button[j].rect.width *= x_size;
            ((game_t *)game)->def_scene[i].button[j].rect.top *= y_size;
            ((game_t *)game)->def_scene[i].button[j].rect.left *= x_size;
        }
    }
    return (0);
}