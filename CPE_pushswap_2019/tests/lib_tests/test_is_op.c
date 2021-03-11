/*
** EPITECH PROJECT, 2019
** test_is_op
** File description:
** test_is_op
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(is_op, simple_number_test)
{
    cr_assert_eq(is_op('+'), 1);
    cr_assert_eq(is_op('-'), 1);
    cr_assert_eq(is_op('*'), 1);
    cr_assert_eq(is_op('/'), 1);
    cr_assert_eq(is_op('%'), 1);
    cr_assert_eq(is_op('('), 1);
    cr_assert_eq(is_op(')'), 1);
}

Test(is_op, simple_not_number_test)
{
    int i = is_op('\n');
    int j = is_op('a');
    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
}