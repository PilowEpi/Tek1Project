/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** function_key
*/

#include "tetris.h"

int drop_key(game_t *game, block_t *tmp)
{
    if (game->info.x + tmp->y >= game->map.x - 1 || collision_or_not(game, tmp))
        return (0);
    game->info.x -= 1;
    for (int k = 0; k < tmp->x; k++)
        game->map.map[game->info.x][game->info.y + k] = ' ';
    for (int i = 0; tmp->form[i]; i++) {
        for (int j = 0; tmp->form[i][j]; j++) {
            game->map.map[game->info.x + i + 1][game->info.y + j] =
                tmp->form[i][j];
        }
    }
    game->info.x += 1;
    draw_game(game);
    game->info.x += 1;
    return (0);
}

int pause_key(game_t *game, block_t *tmp)
{
    if (game->tetris_info.is_paused == 1)
        game->tetris_info.is_paused = 0;
    else
        game->tetris_info.is_paused = 1;
    return (0);
}

int left_key(game_t *game, block_t *tmp)
{
    if (game->info.y <= 1
        || game->map.map[game->info.x][game->info.y - 1] == '*')
        return (0);
    game->info.x -= 1;
    for (int k = 0; k < tmp->y; k++)
        for (int z = 0; z < tmp->x; z++)
        game->map.map[game->info.x + k][game->info.y + z] = ' ';
    for (int i = 0; tmp->form[i]; i++)
        for (int j = 0; tmp->form[i][j]; j++)
            game->map.map[game->info.x + i][game->info.y + j - 1] =
                tmp->form[i][j];
    game->info.y -= 1;
    draw_game(game);
    game->info.x += 1;
    return (0);
}

int right_key(game_t *game, block_t *tmp)
{
    if (game->info.y + tmp->x >= game->map.y - 1)
        return (0);
    game->info.x -= 1;
    for (int k = 0; k < tmp->y; k++)
        for (int z = 0; z < tmp->x; z++)
        game->map.map[game->info.x + k][game->info.y - z] = ' ';
    for (int i = 0; tmp->form[i]; i++) {
        for (int j = 0; tmp->form[i][j]; j++) {
            game->map.map[game->info.x + i][game->info.y + j + 1] =
                tmp->form[i][j];
        }
    }
    game->info.y += 1;
    draw_game(game);
    game->info.x += 1;
    return (0);
}

int turn_key(game_t *game, block_t *tmp)
{
    return (0);
}