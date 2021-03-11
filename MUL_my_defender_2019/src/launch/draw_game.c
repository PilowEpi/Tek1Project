/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_game
*/

#include "defender.h"
#include "struct_defender.h"
#include "dico_defender.h"

int draw_game(window_t *win, game_t *game)
{
    for (int i = 0; draw_tab[i].draw; i++) {
        if (win->type_scene == draw_tab[i].type_scene) {
            draw_tab[i].draw(win, game);
        }
    }
    if (sfRenderWindow_getSize(win->window).x != win->win_size.x) {
        sfRenderWindow_setSize(win->window, win->win_size);
    }
    return (0);
}