/*
** EPITECH PROJECT, 2019
** test_my_printf_p.c
** File description:
** test_my_printf_p
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(my_printf, simple_pointer_int, .init = redirect_all_std)
{
    int i = 1;
    int result = 0;
    my_printf("%p", &i);
    cr_assert_eq(result, 0);
}