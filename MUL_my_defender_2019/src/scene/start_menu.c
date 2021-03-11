/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_menu
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

void draw_menu_sprite(window_t *win, scene_t *menu)
{
    for (int i = 0; i < menu->nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, menu->sprite[i].img, NULL);
        sfSprite_setPosition(menu->sprite[i].img,
                            menu->sprite[i].vect);
    }
}

void draw_menu_button(window_t *win, scene_t *menu)
{
    for (int i = 0; i < menu->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                menu->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(menu->button[i].b_sprite.img,
                            menu->button[i].b_sprite.vect);
    }
}

void draw_menu(window_t *win, scene_t *menu)
{
    draw_menu_sprite(win, menu);
    draw_menu_button(win, menu);
}

int start_menu(window_t *win, game_t *game)
{
    manage_event_menu(win, game);
    draw_menu(win, &game->def_scene[0]);
    return (0);
}