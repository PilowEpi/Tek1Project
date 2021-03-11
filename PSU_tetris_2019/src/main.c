/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** main
*/

#include <ncurses.h>
#include "tetris.h"
#include "my.h"
#include <stdlib.h>

void free_game(game_t *game)
{
    block_t *tmp = game->block;
    block_t *old = NULL;

    while (tmp) {
        old = tmp;
        tmp = tmp->next;
        if (old->form)
            free_my_str_array(old->form);
        free(old->name);
        free(old);
    }
    free(tmp);
    free(game);
}

int start_tetris(int ac, char **av, game_t *game)
{
    int error = 0;

    init_data(&game->data);
    error = get_option(ac, av, &game->data);
    if (error)
        return (error);
    else if (game->data.debug_mode)
        start_debug_mode(&game->data, game);
    game->tetris_info.level = game->data.start_level;
    return (0);
}

int init_tetris(int ac, char **av)
{
    game_t *game = init_game();
    int error = 0;

    if (!game)
        return (84);
    error = start_tetris(ac, av, game);
    if (!error) {
        games_ncurses(game);
        free_game(game);
        return (0);
    } else if (error == 1) {
        return (0);
    }
    return (error);
}

int main(int ac, char **av, char **env)
{
    srand(av[0][0]);
    if (my_strcmp(av[0], "./tetris") != 0) {
        return (84);
    } else if (env[0] == NULL) {
        return (84);
    }
    return (init_tetris(ac, av));
}