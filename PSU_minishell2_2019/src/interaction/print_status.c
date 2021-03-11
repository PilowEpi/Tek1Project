/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** print_status
*/

#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "my.h"
#include "mysh.h"

int print_signal(int status)
{
    switch (status) {
        case SIGFPE :
            my_put_error("Floating exception");
            break;
        default:
            my_put_error(strsignal(status));
            break;
    }
    return (0);
}

int print_status(int status, shell_t *shell)
{
    if (WIFSIGNALED(status)) {
        print_signal(WTERMSIG(status));
        WCOREDUMP(status) ?
            my_put_error(" (core dumped)\n") : my_put_error("\n");
        shell->exit_value = status;
    } else if (WIFEXITED(status)) {
        shell->exit_value = WEXITSTATUS(status);
    }
    return (0);
}