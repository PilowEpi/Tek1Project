/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_move_over_wall
*/

#include <criterion/criterion.h>
#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

char *get_map_blocked(void)
{
    char *map = "#######\n#  #  #\n# #P# #\n#  #  #\n#######\n";

    return (map);
}

Test(move_player, over_wall_rigth_move)
{
    game_t game;
    char *map = get_map_blocked();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_RIGHT);
    cr_assert_eq(game.map[2][3], 'P');
    cr_assert_neq(game.map[2][4], 'P');
}

Test(move_player, over_wall_left_move)
{
    game_t game;
    char *map = get_map_blocked();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_LEFT);
    cr_assert_eq(game.map[2][3], 'P');
    cr_assert_neq(game.map[2][2], 'P');
}

Test(move_player, over_wall_up_move)
{
    game_t game;
    char *map = get_map_blocked();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_UP);
    cr_assert_eq(game.map[2][3], 'P');
    cr_assert_neq(game.map[1][3], 'P');
}

Test(move_player, over_wall_down_move)
{
    game_t game;
    char *map = get_map_blocked();

    game.map = my_str_to_word_array(map);
    find_player(&game);
    key_pressed(&game, KEY_DOWN);
    cr_assert_eq(game.map[2][3], 'P');
    cr_assert_neq(game.map[3][3], 'P');
}