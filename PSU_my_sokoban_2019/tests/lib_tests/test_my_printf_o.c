/*
** EPITECH PROJECT, 2019
** test_my_printf_o.c
** File description:
** test_my_printf_o
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_octal, .init = redirect_all_std)
{
    my_printf("octal i = %o\n", 7);
    my_printf("octal i = %o", 8);
    cr_assert_stdout_eq_str("octal i = 7\noctal i = 10");
}

Test(my_printf, double_flags_octal, .init = redirect_all_std)
{
    my_printf("%o%o", 8, 7);
    cr_assert_stdout_eq_str("107");
}

Test(my_printf, big_flags_octal, .init = redirect_all_std)
{
    my_printf("%o", 1111111);
    cr_assert_stdout_eq_str("4172107");
}