/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** swap_world
*/

#include "defender.h"
#include "struct_defender.h"

int touch_add(void *data, void *win, void *game)
{
    if (((game_t *)game)->data.type != 3)
        ((game_t *)game)->data.type += 1;
    else
        ((game_t *)game)->data.type = 0;
    return (0);
}

int touch_sub(void *data, void *win, void *game)
{
    if (((game_t *)game)->data.type != 0)
        ((game_t *)game)->data.type -= 1;
    else
        ((game_t *)game)->data.type = 3;
}