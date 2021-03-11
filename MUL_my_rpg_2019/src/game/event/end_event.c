/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** end_event
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int end_event(glo_t *gl)
{
    while (sfRenderWindow_pollEvent(gl->win.window,
        &gl->scenes[END_MENU].event)) {
        handle_event(gl->win.window, &gl->scenes[END_MENU].event, gl);
        button_evt_poll(&gl->win, gl, END_MENU);
    }
    return (0);
}

int main_event(glo_t *gl)
{
    while (sfRenderWindow_pollEvent(gl->win.window,
        &gl->scenes[END_MENU].event)) {
        handle_event(gl->win.window, &gl->scenes[END_MENU].event, gl);
        handle_main_event(gl->win.window, &gl->scenes[END_MENU].event,
            gl->data);
    }
    return (0);
}
