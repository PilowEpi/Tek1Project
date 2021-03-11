/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_scene
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

void draw_scene_sprite(window_t *win, scene_t *scene)
{
    for (int i = 0; i < scene->nb_sprite; i++) {
        sfRenderWindow_drawSprite(win->window, scene->sprite[i].img, NULL);
        sfSprite_setPosition(scene->sprite[i].img,
                            scene->sprite[i].vect);
    }
}

void draw_scene_button(window_t *win, scene_t *scene)
{
    for (int i = 0; i < scene->nb_button; i++) {
        sfRenderWindow_drawSprite(win->window,
                                scene->button[i].b_sprite.img, NULL);
        sfSprite_setPosition(scene->button[i].b_sprite.img,
                            scene->button[i].b_sprite.vect);
    }
}

void draw_scene_text(window_t *win, scene_t *scene)
{
    for (int i = 0; i < scene->nb_text; i++) {
        sfText_setPosition(scene->text[i].text, scene->text[i].pos);
        sfRenderWindow_drawText(win->window,
                                scene->text[i].text, NULL);
    }
}

int draw_scene(glo_t *gl)
{
    int nb_scene = gl->nb_scene;

    for (int i = 0; draw_s[i].draw; i++) {
        if (gl->curr_scene == draw_s[i].type_scene) {
            draw_s[i].draw(gl);
        }
    }
    return (0);
}
