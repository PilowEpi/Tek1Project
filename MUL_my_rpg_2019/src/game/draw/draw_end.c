/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_end
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

int draw_end_text(window_t *win, scene_t *scene, int status)
{
    sfText_setPosition(scene->text[status].text, scene->text[status].pos);
    sfRenderWindow_drawText(win->window,
                            scene->text[status].text, NULL);
}

int draw_end(glo_t *gl)
{
    end_event(gl);
    draw_scene_sprite(&gl->win, &gl->scenes[END_MENU]);
    draw_scene_button(&gl->win, &gl->scenes[END_MENU]);
    draw_end_text(&gl->win, &gl->scenes[END_MENU], gl->goal);
    return (0);
}
