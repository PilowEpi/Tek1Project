/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_levels
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

void draw_levels_sprite(window_t *win, scene_t *levels, int t_world)
{
    sfRenderWindow_drawSprite(win->window, levels->sprite[t_world].img, NULL);
    sfSprite_setPosition(levels->sprite[t_world].img,
                        levels->sprite[t_world].vect);
    sfRenderWindow_drawSprite(win->window, levels->sprite[4].img, NULL);
    sfSprite_setPosition(levels->sprite[4].img,
                        levels->sprite[4].vect);
}

void draw_levels_button(window_t *win, scene_t *levels)
{
    for (int i = 0; i < levels->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                levels->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(levels->button[i].b_sprite.img,
                            levels->button[i].b_sprite.vect);
    }
}

void draw_levels_text(window_t *win, scene_t *levels, int t_world)
{
    for (int i = 4; i < 6; i++) {
        sfText_setPosition(levels->text[i].text, levels->text[i].pos);
        sfRenderWindow_drawText(win->window,
                                levels->text[i].text, NULL);
    }
    sfText_setPosition(levels->text[t_world].text, levels->text[t_world].pos);
    sfRenderWindow_drawText(win->window,
                            levels->text[t_world].text, NULL);
}

void draw_levels(window_t *win, scene_t *levels, int t_world)
{
    draw_levels_sprite(win, levels, t_world);
    draw_levels_button(win, levels);
    draw_levels_text(win, levels, t_world);
}

int start_levels(window_t *win, game_t *game)
{
    int t_world = game->data.type;

    manage_event_levels(win, game);
    draw_levels(win, &game->def_scene[2], t_world);
    return (0);
}