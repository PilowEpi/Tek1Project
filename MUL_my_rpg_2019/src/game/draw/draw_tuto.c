/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_tuto
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

int draw_tuto(glo_t *gl)
{
    tuto_event(gl);
    draw_scene_sprite(&gl->win, &gl->scenes[HOW_TO]);
    draw_scene_button(&gl->win, &gl->scenes[HOW_TO]);
    draw_scene_text(&gl->win, &gl->scenes[HOW_TO]);
    return (0);
}
