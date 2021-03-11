/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_stock_spot
*/

#include <criterion/criterion.h>
#include "sokoban.h"
#include "my.h"

Test(search_spot, verify_count_of_spot)
{
    char **map = my_str_to_word_array("OO\n##\nOO\n");

    cr_assert_eq(search_spot(map), 4);
    free_my_str_array(map);
}

Test(search_spot, verify_no_spot)
{
    char **map = my_str_to_word_array("PP\n##\nXX\n");

    cr_assert_eq(search_spot(map), 0);
    free_my_str_array(map);
}