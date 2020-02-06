/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** print_status
*/

#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"

int print_status(int status, shell_t *shell)
{
    if (WIFSIGNALED(status)) {
        if (WIFSIGNALED(status)) {
            my_printf("Segmentation fault%s\n",
            WCOREDUMP(status) ? " (core dumped)" : "");
        }
        shell->exit_value = status;
    } else if (WIFEXITED(status)) {
        shell->exit_value = WEXITSTATUS(status);
    }
    return (0);
}