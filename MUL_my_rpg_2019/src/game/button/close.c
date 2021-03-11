/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** close
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int close_window(void *data)
{
    sfRenderWindow_close(((glo_t *)data)->win.window);
    return (0);
}
