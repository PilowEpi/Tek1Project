/*
** EPITECH PROJECT, 2019
** test_my_stoi.c
** File description:
** test_my_stoi
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"
#include <stdlib.h>

Test(my_stoi, simple_nb)
{
    char *test = my_stoi(12);
    cr_assert_str_eq(test, "12");
    free(test);
}