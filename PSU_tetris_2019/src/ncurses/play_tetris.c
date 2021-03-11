/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** play_tetris.c
*/

#include "tetris.h"
#include "my.h"
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

int draw_correct_time (game_t *game, block_t *tmp)
{
    static int old_time = 0;
    static int time = 0;
    int second = 0;
    int minute = 0;
    int key = 0;
    int value = 0;

    get_time(game, &second, &minute);
    old_time = time;
    time = second + (minute * 60);
    if (time != old_time) {
        draw_actual_form(game, tmp);
        draw_game(game);
        verify_line(game);
    }
    key = getch();
    value = choose_key(game, key, tmp);
    if (value == 1)
        return (1);
    return (0);
}

int reset_next_form(int *id, game_t *game)
{
    *id = game->map.next_form;
    game->map.next_form = rand()%game->data.size;
    game->map.fix = 0;
    game->info.x = 1;
    game->info.y = game->map.y / 2;
    wclear(game->scene.next_form);
    init_nextform(game);
    return (0);
}

int find_form(game_t *game)
{
    block_t *tmp = game->block;
    static int id = 0;

    for (;tmp && tmp->id != id; tmp = tmp->next);

    if (tmp->error == 0) {
        if (draw_correct_time(game, tmp) == 1)
            return (1);
    } else
        game->map.fix = 1;
    if (game->map.fix == 1) {
        reset_next_form(&id, game);
    }
    tmp = game->block;
    while (tmp->id != game->map.next_form)
        tmp = tmp->next;
    draw_next_form(tmp, game);
    return (0);
}

int play_tetris(game_t *game)
{
    if (find_form(game) == 1)
        return (1);
    print_clock(game);
    print_score(game);
    refresh_game(game);
    return (0);
}