/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_option
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

int draw_option(glo_t *gl)
{
    option_event(gl);
    draw_scene_sprite(&gl->win, &gl->scenes[OPTION]);
    draw_scene_button(&gl->win, &gl->scenes[OPTION]);
    return (0);
}
