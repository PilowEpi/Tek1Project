/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** sound
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "lib_csfml.h"

int mute_sound(void *data)
{
    ((glo_t *)data)->is_sound = 1;
}

int turn_on_sound(void *data)
{
    ((glo_t *)data)->is_sound = 0;
}
