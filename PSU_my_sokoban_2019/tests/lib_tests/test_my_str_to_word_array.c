/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_my_str_to_word_array
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_str_to_word_array,  simple_tab)
{
    char *init = "je\nsuis\nun\ntab.";
    char **result = my_str_to_word_array(init);

    cr_assert_str_eq(result[0], "je");

    free_my_str_array(result);
}