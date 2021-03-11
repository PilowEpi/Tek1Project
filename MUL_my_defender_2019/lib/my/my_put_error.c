/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_put_error
*/

#include "my.h"
#include <unistd.h>

void my_put_error(char *str)
{
    write(2, str, my_strlen(str));
}