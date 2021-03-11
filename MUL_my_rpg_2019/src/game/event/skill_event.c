/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** skill_event
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int skill_event(glo_t *gl)
{
    while (sfRenderWindow_pollEvent(gl->win.window,
        &gl->scenes[SKILL_TREE].event)) {
        handle_event(gl->win.window, &gl->scenes[SKILL_TREE].event, gl);
        button_evt_poll(&gl->win, gl, SKILL_TREE);
    }
    return (0);
}
