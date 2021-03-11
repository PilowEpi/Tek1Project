/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** pause_event
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int pause_event(glo_t *gl)
{
    while (sfRenderWindow_pollEvent(gl->win.window,
        &gl->scenes[PAUSE_MENU].event)) {
        handle_event(gl->win.window, &gl->scenes[PAUSE_MENU].event, gl);
        button_evt_poll(&gl->win, gl, PAUSE_MENU);
    }
    return (0);
}
