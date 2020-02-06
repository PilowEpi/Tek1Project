/*
** EPITECH PROJECT, 2019
** test_my_printf_sm.c
** File description:
** test_my_printf_sm
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_S, .init = redirect_all_std)
{
    char *init = "test";
    char *result = my_strdup(init);
    result[2] = 12;
    my_printf("%S", result);
    cr_assert_stdout_eq_str("te\\014t");
    free(result);
}