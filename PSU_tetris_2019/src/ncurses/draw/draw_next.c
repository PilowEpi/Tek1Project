/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** draw_next.c
*/

#include "tetris.h"
#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

int collision_or_not(game_t *game, block_t *tmp)
{
    for (int i = 0; tmp->collision[i][0] != -1; i++) {
        if (game->map.map[game->info.x + tmp->collision[i][0]]
        [game->info.y + tmp->collision[i][1]] == '*')
            return (1);
    }
    return (0);
}

void draw_game(game_t *game)
{
    for (int i = 1; i < game->map.x - 1; i++)
        for (int j = 1; j < game->map.y - 1; j++) {
            mvwprintw(game->scene.tetris, i, j, "%c", game->map.map[i][j]);
        }
    wrefresh(game->scene.tetris);
}

void draw_actual_form(game_t *game, block_t *actual)
{
    if (game->info.x + actual->y >= game->map.x
        || collision_or_not(game, actual)) {
        game->map.fix = 1;
        return;
    }
    for (int k = 0; k < actual->x; k++)
        game->map.map[game->info.x - 1][game->info.y + k] = ' ';
    for (int i = 0; actual->form[i]; i++) {
        for (int j = 0; actual->form[i][j]; j++) {
            game->map.map[game->info.x + i][game->info.y + j] =
                actual->form[i][j];
        }
    }
    game->info.x += 1;
}

void draw_next_form(block_t *next_form, game_t *game)
{
    if (next_form->error)
        return;
    wattron(game->scene.next_form, COLOR_PAIR(next_form->color));
    for (int i = 0; next_form->form[i]; i++) {
        mvwprintw(game->scene.next_form, 2 + i, 15, "%s", next_form->form[i]);
    }
    wattroff(game->scene.next_form, COLOR_PAIR(next_form->color));
    wrefresh(game->scene.next_form);
}