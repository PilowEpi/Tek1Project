/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_end
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int make_win(void *data)
{
    ((glo_t *)data)->goal = 1;
    return (0);
}

int make_lose(void *data)
{
    ((glo_t *)data)->goal = 0;
    return (0);
}

int swap_to_play(void *data)
{
    ((glo_t *)data)->curr_scene = IN_GAME;
    return (0);
}
