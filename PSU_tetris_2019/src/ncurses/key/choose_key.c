/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** choose_key
*/

#include "tetris.h"

int quit_key(game_t *game, block_t *tmp)
{
    return (1);
}

int choose_key(game_t *game, int key, block_t *tmp)
{
    int key_final[] = {game->data.key_left, game->data.key_right,
        game->data.key_turn, game->data.key_drop, game->data.key_quit,
        game->data.key_pause};
    int (*key_fct[])(game_t *game, block_t *tmp) = {&left_key, &right_key,
        &turn_key, &drop_key, &quit_key, &pause_key};
    for (int i = 0; i < 6; i++) {
        if (key == key_final[i]) {
            refresh_game(game);
            return (key_fct[i](game, tmp));
        }
    }
    return (0);
}