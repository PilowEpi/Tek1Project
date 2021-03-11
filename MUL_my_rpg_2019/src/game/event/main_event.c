/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** main_event
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "my.h"

int handle_event(sfRenderWindow *win, sfEvent *event, glo_t *gl)
{
    switch (event->type) {
        case sfEvtClosed :
            sfRenderWindow_close(win);
            break;
        default :
            break;
    }
    return (0);
}
