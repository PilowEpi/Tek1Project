/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** close
*/

#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"

int close_window(void *data, void *win, void *game)
{
    sfRenderWindow_close(((window_t *)win)->window);
    return (0);
}