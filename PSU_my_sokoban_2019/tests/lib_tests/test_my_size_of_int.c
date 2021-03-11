/*
** EPITECH PROJECT, 2019
** test_my_size_of_int.c
** File description:
** test_my_size_of_int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_size_of_int, simple_int)
{
    cr_assert_eq(my_size_of_int(123), 3);
    cr_assert_eq(my_size_of_int(1), 1);
}

Test(my_size_of_int, negative_int)
{
    cr_assert_eq(my_size_of_int(-28), 2);
    cr_assert_eq(my_size_of_int(-4), 1);
}