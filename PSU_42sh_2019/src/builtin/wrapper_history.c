/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins history
*/

#include <unistd.h>
#include <stdlib.h>

#include "sh.h"
#include "my.h"

int wrap_history(int ac, char **av, shell_t *sh)
{
    show_history(sh);
    return (0);
}