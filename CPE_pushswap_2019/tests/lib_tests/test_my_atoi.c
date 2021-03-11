/*
** EPITECH PROJECT, 2019
** test_my_atoi.c
** File description:
** test_my_atoi
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_atoi, simple_src)
{
    cr_assert_eq(my_atoi("123"), 123);
}