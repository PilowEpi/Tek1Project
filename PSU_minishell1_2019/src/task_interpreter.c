/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** task_interpreter
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "mysh.h"

int command_listing(char *cmd, char **args, shell_t *shell)
{
    int i = 0;

    for (; builtin[i].funct != NULL; i++) {
        if (my_matches(cmd, builtin[i].funct) == 0) {
            builtin[i].fct_ptr(shell, args);
            break;
        }
    }
    if (builtin[i].funct == NULL) {
        my_put_error(cmd);
        my_put_error(": Command not found.\n");
    }
    return (0);
}

int task_interpreter(char *input, shell_t *shell)
{
    char **cmd = NULL;

    if (clean_str(input) != 84) {
        cmd = my_parse_shell(input);
        if (cmd != NULL) {
            command_listing(cmd[0], cmd, shell);
        }
    }
    return (0);
}