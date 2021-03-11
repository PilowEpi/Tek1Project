/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_stock_spot
*/

#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"

Test(stock_spot, basic_stock_spot)
{
    game_t game;

    game.map = my_str_to_word_array("OOO\n###\nPXXX\n");
    cr_assert_eq(stock_spot(&game), 0);
    free_my_str_array(game.map);
    free(game.spot_pos);
}

Test(stock_spot, verify_pos_of_spot)
{
    game_t game;

    game.map = my_str_to_word_array("OOO\n###\nPXXX\n");
    stock_spot(&game);
    cr_assert_eq(game.spot_pos[0].x, 0);
    cr_assert_eq(game.spot_pos[0].y, 0);
    cr_assert_eq(game.spot_pos[1].x, 1);
    cr_assert_eq(game.spot_pos[1].y, 0);
    cr_assert_eq(game.spot_pos[2].x, 2);
    cr_assert_eq(game.spot_pos[2].y, 0);
    free_my_str_array(game.map);
    free(game.spot_pos);
}

Test(stock_spot, verify_visiblity_of_spot)
{
    game_t game;

    game.map = my_str_to_word_array("OOO\n###\nPXXX\n");
    stock_spot(&game);
    cr_assert_eq(game.spot_pos[0].is_visible, 1);
    cr_assert_eq(game.spot_pos[1].is_visible, 1);
    cr_assert_eq(game.spot_pos[2].is_visible, 1);
    free_my_str_array(game.map);
    free(game.spot_pos);
}