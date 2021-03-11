/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_condition_game
*/

#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"

Test(verify_condition, verify_lose_map)
{
    game_t game;

    game.map = my_str_to_word_array("####\n#XP#\n####\n");
    game.p.x = 0;
    game.p.y = 0;
    game.count_spot = 1;

    cr_assert_eq(losing_condition(&game), 1);
}

Test(verify_condition, verify_not_lose_map)
{
    game_t game;

    game.map = my_str_to_word_array("# ##\n XP#\n####\n");
    game.p.x = 0;
    game.p.y = 0;
    game.count_spot = 1;

    cr_assert_eq(losing_condition(&game), 0);
}