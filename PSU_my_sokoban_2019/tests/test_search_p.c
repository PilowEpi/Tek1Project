/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_search_p
*/

#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"

Test(find_player, find_basic)
{
    game_t game;

    game.map = my_str_to_word_array("###\n#P#\n###\n");
    game.p.x = 0;
    game.p.y = 0;

    find_player(&game);

    cr_assert_eq(game.p.x, 1);
    cr_assert_eq(game.p.y, 1);
    free_my_str_array(game.map);
}