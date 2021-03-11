/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_pause
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"
#include "my.h"

void pause_mouse_over(window_t *win, game_t *game)
{
    win->mouse_vect = sfMouse_getPositionRenderWindow(win->window);

    for (int i = 0; i < game->def_scene[PAUSE].nb_button; i++) {
        if (sfFloatRect_contains(&(game->def_scene[PAUSE].button[i].rect),
            win->mouse_vect.x, win->mouse_vect.y))
            sfSprite_setTextureRect(game->def_scene[PAUSE].button[i].b_sprite.
                img, game->def_scene[PAUSE].button[i].rect_tab[1]);
        else
            sfSprite_setTextureRect(game->def_scene[PAUSE].button[i].b_sprite.
                img, game->def_scene[PAUSE].button[i].rect_tab[0]);
    }
}

void pause_click_evt(window_t *win, game_t *game, int img)
{
    if (game->def_scene[PAUSE].event.type == sfEvtMouseButtonReleased) {
        game->def_scene[PAUSE].button[img].fct(&img, win, game);
        sfSprite_setTextureRect(game->def_scene[PAUSE].button[img].b_sprite.
            img, game->def_scene[PAUSE].button[img].rect_tab[1]);
    }
}

void pause_evt_mouse(window_t *win, game_t *game)
{
    int i = 0;

    win->mouse_vect = sfMouse_getPositionRenderWindow(win->window);
    for (; i < game->def_scene[PAUSE].nb_button; i++) {
        if (sfFloatRect_contains(&(game->def_scene[PAUSE].button[i].rect),
            win->mouse_vect.x, win->mouse_vect.y)) {
            sfSprite_setTextureRect(game->def_scene[PAUSE].button[i].b_sprite.
                img, game->def_scene[PAUSE].button[i].rect_tab[2]);
            pause_click_evt(win, game, i);
        }
    }
}

void pause_evt_poll(window_t *win, game_t *game)
{
    switch (game->def_scene[PAUSE].event.type) {
        case sfEvtClosed :
            sfRenderWindow_close(win->window);
            break;
        case sfEvtMouseButtonPressed :
        case sfEvtMouseButtonReleased :
            pause_evt_mouse(win, game);
            break;
        case sfEvtKeyPressed :
            if (game->def_scene[PAUSE].event.key.code == sfKeyEscape)
                win->type_scene = IN_GAME;
            break;
        default:
            pause_mouse_over(win, game);
            break;
    }
}

int manage_event_pause(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window,
            &game->def_scene[PAUSE].event)) {
        pause_evt_poll(win, game);
    }
    return (0);
}