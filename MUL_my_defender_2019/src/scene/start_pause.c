/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_pause
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

void draw_pause_sprite(window_t *win, scene_t *pause)
{
    for (int i = 0; i < pause->nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, pause->sprite[i].img, NULL);
        sfSprite_setPosition(pause->sprite[i].img,
                            pause->sprite[i].vect);
    }
}

void draw_pause_button(window_t *win, scene_t *pause)
{
    for (int i = 0; i < pause->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                pause->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(pause->button[i].b_sprite.img,
                            pause->button[i].b_sprite.vect);
    }
}

void draw_pause_text(window_t *win, scene_t *pause)
{
    for (int i = 0; i < pause->nb_text; i++) {
        sfText_setPosition(pause->text[i].text, pause->text[i].pos);
        sfRenderWindow_drawText(win->window,
                                pause->text[i].text, NULL);
    }
}

void draw_pause(window_t *win, scene_t *pause)
{
    draw_pause_sprite(win, pause);
    draw_pause_button(win, pause);
    draw_pause_text(win, pause);
}

int start_pause(window_t *win, game_t *game)
{
    manage_event_pause(win, game);
    draw_pause(win, &game->def_scene[PAUSE]);
    return (0);
}