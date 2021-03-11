/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** test_usage
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "sokoban.h"

Test(usage, test_usage, .init = cr_redirect_stdout)
{
    cr_assert_eq(usage_instructions(), 0);
}