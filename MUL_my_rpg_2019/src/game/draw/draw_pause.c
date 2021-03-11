/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_pause
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

int draw_pause(glo_t *gl)
{
    pause_event(gl);
    draw_scene_sprite(&gl->win, &gl->scenes[PAUSE_MENU]);
    draw_scene_button(&gl->win, &gl->scenes[PAUSE_MENU]);
    draw_scene_text(&gl->win, &gl->scenes[PAUSE_MENU]);
    return (0);
}
