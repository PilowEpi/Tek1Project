/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_map_verifier
*/

#include <criterion/criterion.h>
#include "sokoban.h"

Test(is_invalid_map, simple_double_p_map)
{
    char map[] = "######\n#P P#\n####";

    cr_assert_eq(is_invalid_map(map), 84);
}

Test(is_invalid_map, simple_no_p_in_map)
{
    char map[] = "######\n#   #\n####";

    cr_assert_eq(is_invalid_map(map), 84);
}