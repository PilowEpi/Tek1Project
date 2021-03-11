/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_map_verifier_o
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(is_invalid_map, simple_not_enough_x)
{
    char map[] = "P O XO";

    cr_assert_eq(is_invalid_map(map), 84);
}

Test(is_invalid_map, simple_no_x)
{
    char map[] = "P O O";

    cr_assert_eq(is_invalid_map(map), 84);
}