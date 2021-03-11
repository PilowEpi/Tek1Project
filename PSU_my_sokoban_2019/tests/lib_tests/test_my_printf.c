/*
** EPITECH PROJECT, 2019
** test_my_printf.c
** File description:
** test my_printf.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("Hello");
    cr_assert_stdout_eq_str("Hello");
}

Test(my_printf, special_string, .init = redirect_all_std)
{
    my_printf("Hello\thello\n");
    cr_assert_stdout_eq_str("Hello\thello\n");
}

Test(my_printf, double_percent, .init = redirect_all_std)
{
    my_printf("%%\n");
    cr_assert_stdout_eq_str("%\n");
}

Test(my_printf, unknown_flags, .init = redirect_all_std)
{
    my_printf("%M");
    cr_assert_stdout_eq_str("%M");
}

Test(my_printf, without_str, .init = redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}