/*
** EPITECH PROJECT, 2019
** redirect_all_std.c
** File description:
** redirect_all_std
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}