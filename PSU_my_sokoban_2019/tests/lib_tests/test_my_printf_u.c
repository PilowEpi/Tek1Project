/*
** EPITECH PROJECT, 2019
** test_my_printf_u.c
** File description:
** test_my_printf_u
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_unsigned, .init = redirect_all_std)
{
    my_printf("%u\n", 20);
    my_printf("%u\n", 100);
    my_printf("%u\n", 11);
    my_printf("%u\n", 7);
    cr_assert_stdout_eq_str("20\n100\n11\n7\n");
}