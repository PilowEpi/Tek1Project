/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** simple_exe
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
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

int simple_listing(char *cmd, char **args, shell_t *shell)
{
    int i = 0;

    for (; builtin[i].funct != NULL; i++) {
        if (i != 4 && my_matches(cmd, builtin[i].funct) == 0) {
            builtin[i].fct_ptr(shell, args);
            break;
        } else if (i == 5 && my_matches(cmd, builtin[i].funct) == 0) {
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

void simple_exe(shell_t *shell, char **args)
{
    int pid = 0;
    int status = 0;
    int exe_err = 0;

    pid = fork();

    if (pid == 0) {
        my_exe(shell, args);
        exit(exe_err);
    }
    waitpid(pid, &status, 0);
    print_status(status, shell);
}