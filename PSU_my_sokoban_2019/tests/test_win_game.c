/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_win_game
*/

#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"

Test(winning_condition, verify_win_game)
{
    game_t game;

    game.map = my_str_to_word_array("OOO\n###\nPXXX\n");
    stock_spot(&game);
    game.spot_pos[0].is_visible = 0;
    game.spot_pos[1].is_visible = 0;
    game.spot_pos[2].is_visible = 0;

    game.spot_pos[0].x = 1;
    game.spot_pos[1].x = 2;
    game.spot_pos[2].x = 3;
    game.spot_pos[0].y = 2;
    game.spot_pos[1].y = 2;
    game.spot_pos[2].y = 2;
    verify_condition(&game);
    cr_assert_eq(game.condition, 0);
    free_my_str_array(game.map);
    free(game.spot_pos);
}

Test(winning_condition, verify_no_game)
{
    game_t game;

    game.map = my_str_to_word_array("#####\n#XXX#\n#  O#\n#OOP#\n#####\n");
    stock_spot(&game);
    game.condition = 1;

    game.spot_pos[0].is_visible = 1;
    verify_condition(&game);
    cr_assert_neq(game.condition, 0);
    free_my_str_array(game.map);
    free(game.spot_pos);
}