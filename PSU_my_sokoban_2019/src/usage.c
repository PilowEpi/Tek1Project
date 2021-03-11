/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** usage
*/

#include "my.h"

int usage_instructions(void)
{
    my_printf("USAGE\n");
    my_printf("    ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("    map  file representing the warehouse map, containing '#' ");
    my_printf("for walls, \n         'P' for the player, 'X' for boxes and");
    my_printf(" 'O' for storage locations.\n");
    return (0);
}