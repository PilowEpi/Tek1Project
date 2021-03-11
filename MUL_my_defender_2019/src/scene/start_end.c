/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_end
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

void draw_end_sprite(window_t *win, scene_t *end)
{
    for (int i = 0; i < end->nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, end->sprite[i].img, NULL);
        sfSprite_setPosition(end->sprite[i].img,
                            end->sprite[i].vect);
    }
}

void draw_end_button(window_t *win, scene_t *end)
{
    for (int i = 0; i < end->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                end->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(end->button[i].b_sprite.img,
                            end->button[i].b_sprite.vect);
    }
}

void draw_end_text(window_t *win, game_t *game)
{
    scene_t scene = game->def_scene[END_GAME];

    if (game->level->health <= 0) {
        sfText_setPosition(scene.text[0].text, scene.text[0].pos);
        sfRenderWindow_drawText(win->window,
                                scene.text[0].text, NULL);
    } else {
        sfText_setPosition(scene.text[1].text, scene.text[1].pos);
        sfRenderWindow_drawText(win->window,
                                scene.text[1].text, NULL);
    }
}

void draw_end(window_t *win, game_t *game)
{
    draw_end_sprite(win, &game->def_scene[END_GAME]);
    draw_end_button(win, &game->def_scene[END_GAME]);
    draw_end_text(win, game);
}

int start_end(window_t *win, game_t *game)
{
    manage_event_end(win, game);
    draw_end(win, game);
    return (0);
}