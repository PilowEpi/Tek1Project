/*
** EPITECH PROJECT, 2019
** test_disp_stdarg.c
** File description:
** test_disp_stdarg
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "tests.h"

Test(disp_stdarg, simple_string, .init = redirect_all_std)
{
    disp_stdarg("csi", 'O', "test", 117);
    cr_assert_stdout_eq_str("O\ntest\n117\n");
}