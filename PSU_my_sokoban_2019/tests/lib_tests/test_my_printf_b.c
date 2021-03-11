/*
** EPITECH PROJECT, 2019
** test_my_printf_b.c
** File description:
** test_my_printf_b
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_bin, .init = redirect_all_std)
{
    my_printf("%b", 20);
    cr_assert_stdout_eq_str("10100");
}