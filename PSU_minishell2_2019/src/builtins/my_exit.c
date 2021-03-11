/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_exit
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void my_free_env(list_t *list)
{
    chain_t *tmp = list->head;
    chain_t *to_free;

    while (tmp != NULL) {
        to_free = tmp;
        tmp = tmp->next;
        free(to_free->name_env);
        free(to_free->env_value);
        free(to_free);
    }
}

int verify_exit_value(char *exit_value)
{
    if (!is_num(exit_value[0]) && exit_value[0] != '-') {
        my_put_error("exit: Expression Syntax.\n");
        return (2);
    }
    for (int i = 1; exit_value[i]; i++) {
        if (!is_num(exit_value[i])) {
            my_put_error("exit: Badly formed number.\n");
            return (1);
        }
    }
    return (0);
}

void my_exit(shell_t *shell, char **args)
{
    if (args == NULL || args[1] == NULL) {
        shell->state = OFF;
        my_free_env(&shell->env);
        (isatty(0)) ? my_printf("exit\n") : 0;
        exit(shell->exit_value);
    } else if (args[1] != NULL) {
        if (!verify_exit_value(args[1])) {
            shell->exit_value = my_getnbr(args[1]);
            my_free_env(&shell->env);
            (isatty(0)) ? my_printf("exit\n") : 0;
            exit(shell->exit_value);
        } else {
            shell->exit_value = 1;
            return;
        }
    }
    my_free_env(&shell->env);
    exit(shell->exit_value);
}