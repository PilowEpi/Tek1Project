/*
** EPITECH PROJECT, 2019
** test_my_printf_s.c
** File description:
** test_my_printf_s
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_flags_string, .init = redirect_all_std)
{
    my_printf("Hello World %s", "test");
    cr_assert_stdout_eq_str("Hello World test");
}

Test(my_printf, double_flags_string, .init = redirect_all_std)
{
    my_printf("Hello %s World %s", "test", "toto");
    cr_assert_stdout_eq_str("Hello test World toto");
}

Test(my_printf, multiple_flags_handle, .init = redirect_all_std)
{
    my_printf("%s%s%s%s", "toto", "tata", "titi", "tutu");
    cr_assert_stdout_eq_str("tototatatititutu");
}

Test(my_printf, simple_flags_newline_handle, .init = redirect_all_std)
{
    my_printf("%s \n", "toto");
    my_printf("%s\n", "titi");
    cr_assert_stdout_eq_str("toto \ntiti\n");
}