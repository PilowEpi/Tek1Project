/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defender_scene_draw
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

void draw_defender_text(window_t *win, scene_t *option)
{
    for (int i = 0; i < option->nb_text; i++) {
        sfText_setPosition(option->text[i].text, option->text[i].pos);
        sfRenderWindow_drawText(win->window,
                                option->text[i].text, NULL);
    }
}

void draw_defender_sprite(window_t *win, scene_t *menu)
{
    for (int i = 0; i < menu->nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, menu->sprite[i].img, 0);
        sfSprite_setPosition(menu->sprite[i].img,
                            menu->sprite[i].vect);
    }
}

void draw_defender_button(window_t *win, scene_t *menu, game_t *game)
{
    int start = 0;
    int end = 0;

    for (int i = 0; hud[i].state < NOT_A_CELL; i++) {
        if (hud[i].state != game->level->hud) {
            start += hud[i].button_count;
        } else {
            end = start + hud[i].button_count;
            break;
        }
    }
    for (int i = start; i < end && i < menu->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                menu->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(menu->button[i].b_sprite.img,
                            menu->button[i].b_sprite.vect);
    }
}