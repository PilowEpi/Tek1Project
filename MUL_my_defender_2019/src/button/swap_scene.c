/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** swap_scene
*/

#include "struct_defender.h"
#include "defender.h"

int swap_to_menu(void *data, void *win, void *gam)
{
    ((window_t *)win)->type_scene = MENU;
    return (0);
}

int swap_to_in_game(void *data, void *win, void *game)
{
    if (((game_t *)game)->level != NULL) {
        destroy_level((window_t *) win, (game_t *) game);
    }
    initialize_level(data, win, game);
    sfRenderWindow_setView(((window_t *)win)->window, ((game_t *)game)->view);
    ((window_t *)win)->type_scene = IN_GAME;
    return (0);
}

int swap_to_option(void *data, void *win, void *game)
{
    ((window_t *)win)->type_scene = OPTION;
    return (0);
}

int swap_to_end_game(void *data, void *win, void *game)
{
    ((window_t *)win)->type_scene = END_GAME;
    return (0);
}

int swap_to_levels(void *data, void *win, void *game)
{
    ((window_t *)win)->type_scene = LEVELS;
    return (0);
}