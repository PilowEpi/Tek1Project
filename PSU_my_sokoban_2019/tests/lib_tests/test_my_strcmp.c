/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_my_strcmp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_strcmp, simple_test)
{
    char *init = "lol";
    int comparaison = my_strcmp(init, "lol");

    cr_assert_eq(comparaison, 0);
}

Test(my_strcmp, fail_test)
{
    char *init = "lel";
    int comparaison = my_strcmp(init, "lol");

    cr_assert_neq(comparaison, 0);
}