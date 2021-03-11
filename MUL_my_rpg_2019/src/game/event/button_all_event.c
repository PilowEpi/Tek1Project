/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** button_all_event
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

void button_mouse_over(window_t *win, glo_t *game, int scene)
{
    win->mouse_vect = sfMouse_getPositionRenderWindow(win->window);

    for (int i = 0; i < game->scenes[scene].nb_button; i++) {
        if (sfFloatRect_contains(&(game->scenes[scene].button[i].rect),
            win->mouse_vect.x, win->mouse_vect.y)) {
            sfSprite_setTextureRect(game->scenes[scene].button[i].b_sprite.
                img, game->scenes[scene].button[i].rect_tab[1]);
        } else {
            sfSprite_setTextureRect(game->scenes[scene].button[i].b_sprite.
                img, game->scenes[scene].button[i].rect_tab[0]);
        }
    }
}

void button_click_evt(window_t *win, glo_t *game, int img, int scene)
{
    if (game->scenes[scene].event.type == sfEvtMouseButtonReleased) {
        game->scenes[scene].button[img].fct(game);
        sfSprite_setTextureRect(game->scenes[scene].button[img].b_sprite.
            img, game->scenes[scene].button[img].rect_tab[1]);
    }
}

void button_evt_mouse(window_t *win, glo_t *game, int scene)
{
    int i = 0;

    win->mouse_vect = sfMouse_getPositionRenderWindow(win->window);
    for (; i < game->scenes[scene].nb_button; i++) {
        if (sfFloatRect_contains(&(game->scenes[scene].button[i].rect),
            win->mouse_vect.x, win->mouse_vect.y)) {
            sfSprite_setTextureRect(game->scenes[scene].button[i].b_sprite.
                img, game->scenes[scene].button[i].rect_tab[2]);
            button_click_evt(win, game, i, scene);
        }
    }
}

void button_evt_poll(window_t *win, glo_t *game, int scene)
{
    switch (game->scenes[scene].event.type) {
        case sfEvtMouseButtonPressed :
        case sfEvtMouseButtonReleased :
            button_evt_mouse(win, game, scene);
            break;
        default:
            button_mouse_over(win, game, scene);
            break;
    }
}
