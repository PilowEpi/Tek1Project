/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** main_shell
*/

#include <stddef.h>
#include "my.h"
#include "mysh.h"

int launch_shell(char **envp)
{
    shell_t shell;

    shell.state = ON;
    shell.exit_value = 0;
    if (envp != NULL) {
        init_env(envp, &shell.env);
    }
    shell_loop(&shell);
    return (0);
}

int main(int ac, __attribute__((unused))char **args, char **envp)
{
    if (ac != 1)
        return (84);
    launch_shell(envp);
    return (0);
}