/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_option
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

void draw_option_sprite(window_t *win, scene_t *option)
{
    for (int i = 0; i < option->nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, option->sprite[i].img, NULL);
        sfSprite_setPosition(option->sprite[i].img,
                            option->sprite[i].vect);
    }
}

void draw_option_button(window_t *win, scene_t *option)
{
    for (int i = 0; i < option->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                option->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(option->button[i].b_sprite.img,
                            option->button[i].b_sprite.vect);
    }
}

void draw_option_text(window_t *win, scene_t *option)
{
    for (int i = 0; i < option->nb_text; i++) {
        sfText_setPosition(option->text[i].text, option->text[i].pos);
        sfRenderWindow_drawText(win->window,
                                option->text[i].text, NULL);
    }
}

void draw_option(window_t *win, scene_t *option)
{
    draw_option_sprite(win, option);
    draw_option_button(win, option);
    draw_option_text(win, option);
}

int start_option(window_t *win, game_t *game)
{
    manage_event_option(win, game);
    draw_option(win, &game->def_scene[1]);
    return (0);
}