/*
** EPITECH PROJECT, 2019
** test_my_printf_c.c
** File description:
** test_my_printf_c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_char, .init = redirect_all_std)
{
    my_printf("%c", 32);
    my_printf("%c", '\n');
    cr_assert_stdout_eq_str(" \n");
}