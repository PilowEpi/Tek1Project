/*
** EPITECH PROJECT, 2019
** test_sum_stdarg.c
** File description:
** test sum_stdarg.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"


Test(sum_stdarg, return_correct_when_i_is_zero)
{
    int result_t1 = sum_stdarg(0, 3, 20, 10, 30);
    int result_t2 = sum_stdarg(0, 2, 20, -40);
    int	result_t3 = sum_stdarg(0, 2, 19, 1);

    cr_assert_eq(result_t1, 60);
    cr_assert_eq(result_t2, -20);
    cr_assert_eq(result_t3, 20);
}

Test(sum_stdarg, return_correct_when_i_is_one)
{
    int result_t1 = sum_stdarg(1, 3, "Hello", "World", "!");

    cr_assert_eq(result_t1, 11);
}

Test(sum_stdarg, return_correct_when_i_is_over_one)
{
    int result_t1 = sum_stdarg(2, 2, 2, 2);

    cr_assert_eq(result_t1, 84);
}
