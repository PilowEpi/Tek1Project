/*
** EPITECH PROJECT, 2019
** test_my_printf_x.c
** File description:
** test_my_printf_x
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_hexa, .init = redirect_all_std)
{
    my_printf("%x", 10);
    my_printf("%X", 10);
    cr_assert_stdout_eq_str("aA");
}

Test(my_printf, double_flags_hexa, .init = redirect_all_std)
{
    my_printf("%x%x", 10, 10);
    my_printf("%X%X", 10, 10);
    cr_assert_stdout_eq_str("aaAA");
}

Test(my_printf, big_hexa_flags, .init = redirect_all_std)
{
    my_printf("%x%X", 1234567890, 1234567890);
    cr_assert_stdout_eq_str("499602d2499602D2");
}