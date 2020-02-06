/*
** EPITECH PROJECT, 2019
** test_my_printf_i_d.c
** File description:
** test_my_printf_i_d
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_int, .init = redirect_all_std)
{
    my_printf("int i = %d\n", 1);
    my_printf("int i = %i\n", 1);
    my_printf("int i = %d\n", -1);
    my_printf("int i = %d\n", -1);
    cr_assert_stdout_eq_str("int i = 1\nint i = 1\nint i = -1\nint i = -1\n");
}

Test(my_printf, double_flags_int, .init = redirect_all_std)
{
    my_printf("%i%i", 2, 2);
    my_printf("%d%d", 2, 2);
    cr_assert_stdout_eq_str("2222");
}

Test(my_printf, multiple_flags_int, .init = redirect_all_std)
{
    my_printf("%i%i%i%i", 2, 2, 2, 2);
    my_printf("%d%d%d%d", 2, 2, 2, 2);
    cr_assert_stdout_eq_str("22222222");
}