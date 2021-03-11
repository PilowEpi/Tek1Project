/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** swap_scene
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"
#include "lib_csfml.h"

int swap_to_end(void *data)
{
    ((glo_t *)data)->curr_scene = END_MENU;
    return (0);
}

int swap_to_menu(void *data)
{
    ((glo_t *)data)->curr_scene = MENU;
    return (0);
}

int swap_to_pause(void *data)
{
    ((glo_t *)data)->curr_scene = PAUSE_MENU;
    return (0);
}

int swap_to_option(void *data)
{
    ((glo_t *)data)->curr_scene = OPTION;
    return (0);
}

int swap_to_skill(void *data)
{
    ((glo_t *)data)->curr_scene = SKILL_TREE;
    return (0);
}
