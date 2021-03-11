/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_skill
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

int draw_skill(glo_t *gl)
{
    skill_event(gl);
    draw_scene_sprite(&gl->win, &gl->scenes[SKILL_TREE]);
    draw_scene_button(&gl->win, &gl->scenes[SKILL_TREE]);
    draw_scene_text(&gl->win, &gl->scenes[SKILL_TREE]);
    return (0);
}
