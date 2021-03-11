/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_my_strdup
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_strdup, simple_dup)
{
    char *init = "lolilol";
    char *dup = my_strdup(init);

    cr_assert_str_eq(dup, init);
    free(dup);
}