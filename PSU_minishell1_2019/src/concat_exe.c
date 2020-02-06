/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** concat_exe
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int concat_exe(shell_t *shell, char **old_args, char *path, char **envp)
{
    free(old_args[0]);
    old_args[0] = my_strdup(path);
    executable_this(envp, old_args[0], old_args, shell);
    return (0);
}