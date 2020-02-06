/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** test_ia_utility
*/

#include <criterion/criterion.h>
#include "matchstick.h"
#include "my.h"

Test(is_odd, verify_when_simple_map_is_odd)
{
    match_t *game;

    create_map(game, 3);
    cr_assert_eq(is_odd(game), 1);
}

Test(is_odd, verify_when_simple_map_isnt_odd)
{
    match_t *game;

    create_map(game, 4);
    cr_assert_eq(is_odd(game), 0);
}

Test(is_odd, verify_when_map_is_odd)
{
    match_t *game;

    create_map(game, 4);
    game->match_value[0] -= 1;
    cr_assert_eq(is_odd(game), 1);
}

Test(is_odd, verify_when_map_isnt_odd)
{
    match_t *game;

    create_map(game, 5);
    game->match_value[0] -= 1;
    cr_assert_eq(is_odd(game), 0);
}