/*
** EPITECH PROJECT, 2019
** test_is_num.c
** File description:
** test_is_num
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(is_num, simple_number_test)
{
    int i = is_num('9');
    int j = is_num('0');
    cr_assert_eq(i, 1);
    cr_assert_eq(j, 1);
}

Test(is_num, simple_not_number_test)
{
    int i = is_num('-');
    int j = is_num('a');
    cr_assert_eq(i, 0);
    cr_assert_eq(j, 0);
}