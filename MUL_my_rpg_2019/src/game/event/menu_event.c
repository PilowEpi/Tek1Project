/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** menu_event
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int menu_event(glo_t *gl)
{
    sfEvent *event;

    while (sfRenderWindow_pollEvent(gl->win.window, &gl->scenes[MENU].event)) {
        event = &gl->scenes[MENU].event;
        handle_event(gl->win.window, &gl->scenes[MENU].event, gl);
        button_evt_poll(&gl->win, gl, MENU);
        if (event->type == sfEvtKeyPressed)
            gl->counter = 100000;
    }
    return (0);
}
