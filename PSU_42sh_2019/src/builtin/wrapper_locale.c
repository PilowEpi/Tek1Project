/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins locale_var wrapper
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "sh.h"
#include "my.h"

int wrap_set(int ac, char **av, shell_t *sh)
{
    if (ac == 1) {
        lld_sort(sh->l_var, &sort_l_var);
        return (print_locale_variable(sh->l_var));
    }
    if (ac != 3)
        return (!dprintf(2, "Usage: set [name] [value].\n"));
    if (!is_alpha(av[1][0]) && av[1][0] != '_')
        return (dprintf(2, "set: Variable name must begin with a letter.\n"));
    add_locale_var(my_strdup(av[1]), my_strdup(av[2]), sh->l_var);
    return (0);
}

int wrap_unset(int ac, char **av, shell_t *sh)
{
    if (ac == 1)
        return (!dprintf(2, "unset: Too few arguments.\n"));
    del_locale_var(av[1], sh->l_var);
    return (0);
}
