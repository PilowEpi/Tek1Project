/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_map_verifier
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(is_invalid_map, simple_valid_map)
{
    char map[] = "#######\n#P X O#\n########";

    cr_assert_eq(is_invalid_map(map), 0);
}

Test(is_invalid_map, simple_not_enough_o)
{
    char map[] = "P O XX";

    cr_assert_eq(is_invalid_map(map), 84);
}

Test(is_invalid_map, simple_no_o)
{
    char map[] = "P  XX";

    cr_assert_eq(is_invalid_map(map), 84);
}

Test(is_invalid_map, simple_error_map)
{
    char map[] = "yeahhhhh";

    cr_assert_eq(is_invalid_map(map), 84);
}