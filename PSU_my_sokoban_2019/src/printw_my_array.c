/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** get_x_y
*/

#include "sokoban.h"
#include <stddef.h>
#include <ncurses.h>

void printw_my_array(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
        printw("\n");
    }
}