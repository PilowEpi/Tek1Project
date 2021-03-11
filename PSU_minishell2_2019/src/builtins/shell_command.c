/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** shell_command
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void my_env(shell_t *shell, __attribute__((unused))char **args)
{
    print_list_env(&shell->env);
    shell->exit_value = 0;
}

void my_unsetenv(shell_t *shell, char **args)
{
    if (args[1] != NULL) {
        for (int i = 1; args[i] != NULL; i++) {
            my_unset_list(shell, args[i]);
        }
    } else {
        my_put_error("unsetenv: Too few arguments.\n");
        shell->exit_value = 1;
        return;
    }
    shell->exit_value = 0;
}

void my_setenv(shell_t *shell, char **args)
{
    if (args[1] == NULL) {
        print_list_env(&shell->env);
        return;
    }
    if (is_num(args[1][0])) {
        my_put_error("setenv: Variable name must begin with a letter.\n");
        shell->exit_value = 1;
        return;
    } else if (args[2] == NULL || args[3] == NULL) {
        my_setenv_list(shell, args);
    } else {
        my_put_error("setenv: Too many arguments.\n");
        shell->exit_value = 1;
        return;
    }
    shell->exit_value = 0;
}

void my_cd(shell_t *shell, char **args)
{
    int index_home = get_index_of_env(shell, "HOME");
    int index_old_pwd = get_index_of_env(shell, "OLDPWD");
    char *home_value = NULL;
    char *old_pwd_value = NULL;

    if (args[1] == NULL || !my_strcmp(args[1], "~")) {
        if (index_home != -1) {
            home_value = get_value_of_env(shell, index_home);
            (home_value == NULL)? 0 : my_cd_list(shell, home_value);
        }
    } else if (my_strcmp(args[1], "-") == 0) {
        if (index_old_pwd != -1) {
            old_pwd_value = get_value_of_env(shell, index_old_pwd);
            (old_pwd_value == NULL)? 0 : my_cd_list(shell, old_pwd_value);
        }
    } else {
        my_cd_list(shell, args[1]);
    }
}