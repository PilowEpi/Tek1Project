/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_move_player
*/

#include <criterion/criterion.h>
#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

char *get_map(void)
{
    char *map = "#######\n#     #\n#  P  #\n#     #\n#######\n";

    return (map);
}

Test(move_player, simple_rigth_move)
{
    game_t game;
    char *map = get_map();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_RIGHT);
    cr_assert_neq(game.map[2][3], 'P');
    cr_assert_eq(game.map[2][4], 'P');
}

Test(move_player, simple_left_move)
{
    game_t game;
    char *map = get_map();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_LEFT);
    cr_assert_neq(game.map[2][3], 'P');
    cr_assert_eq(game.map[2][2], 'P');
}

Test(move_player, simple_up_move)
{
    game_t game;
    char *map = get_map();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_UP);
    cr_assert_neq(game.map[2][3], 'P');
    cr_assert_eq(game.map[1][3], 'P');
}

Test(move_player, simple_down_move)
{
    game_t game;
    char *map = get_map();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_DOWN);
    cr_assert_neq(game.map[2][3], 'P');
    cr_assert_eq(game.map[3][3], 'P');
}