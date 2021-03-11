/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** draw_tetris.c
*/

#include "tetris.h"
#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

void drawt(int color, int x, int y)
{
    attron(COLOR_PAIR(color));
    for (int i = 0 ;i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    for (x = x - 4; y != 6; y++)
        mvprintw(y, x, "*");
}

void drawe(int color, int x, int y)
{
    attron(COLOR_PAIR(color));
    for (int i = 0; i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    x -= 6;
    mvprintw(2, x, "*");
    for (int i = 0, y = 3; i != 4; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    x -= 4;
    mvprintw(4, x, "*");
    for (int i = 0, y = 5; i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
}

void drawr(int color, int x, int y)
{
    attron(COLOR_PAIR(color));
    for (int i = 0; i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    mvprintw(2, x - 2, "*");
    x -= 6;
    mvprintw(2, x, "*");
    for (int i = 0, y = 3; i != 4; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    mvprintw(4, x, "*");
    x -= 4;
    mvprintw(4, x, "*");
    mvprintw(5, x, "*");
    mvprintw(5, x + 4, "*");
}

void drawi(int color, int x, int y)
{
    attron(COLOR_PAIR(color));
    mvprintw(y, x, "*");
    y += 2;
    mvprintw(y++, x, "*");
    mvprintw(y++, x, "*");
    mvprintw(y, x, "*");
}

void draws(int color, int x, int y)
{
    attron(COLOR_PAIR(color));
    for (int i = 0; i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    x -= 6;
    mvprintw(2, x + 1, "*");
    for (int i = 0, y = 3; i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
    mvprintw(4, x - 1, "*");
    x -= 6;
    for (int i = 0, y = 5; i != 6; x++, i++)
        if (x % 2 == 0)
            mvprintw(y, x, "*");
}