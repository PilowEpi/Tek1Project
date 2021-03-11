/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** generic_move
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

void x_move(game_t *game, int x, int y)
{
    switch(game->map[game->p.y + (y * 2)][game->p.x + (x * 2)]) {
        case 'O':
            index_of_spot(game, game->p.x + (x * 2), game->p.y + (y * 2));
            game->map[game->p.y + (y * 2)][game->p.x + (x * 2)] = 'X';
            game->map[game->p.y + y][game->p.x + x] = 'P';
            game->map[game->p.y][game->p.x] = ' ';
            break;
        case ' ':
            game->map[game->p.y + (y * 2)][game->p.x + (x * 2)] = 'X';
            game->map[game->p.y + y][game->p.x + x] = 'P';
            game->map[game->p.y][game->p.x] = ' ';
            break;
        case 'X':
            break;
    }
}

void generic_move(game_t *game, int x, int y)
{
    switch (game->map[game->p.y + y][game->p.x + x]) {
        case ' ' :
            game->map[game->p.y + y][game->p.x + x] = 'P';
            game->map[game->p.y][game->p.x] = ' ';
            break;
        case 'X':
            x_move(game, x, y);
            break;
        case 'O':
            index_of_spot(game, game->p.x + x, game->p.y + y);
            game->map[game->p.y + y][game->p.x + x] = 'P';
            game->map[game->p.y][game->p.x] = ' ';
            break;
    }
}