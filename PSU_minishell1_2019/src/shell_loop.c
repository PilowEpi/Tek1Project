/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** shell_loop
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int shell_loop(shell_t *shell)
{
    char *input = NULL;

    while (shell->state != OFF) {
        input = get_user_input();
        if (input == NULL && isatty(0))
            my_printf("exit\n");
        if (input == NULL) {
            free(input);
            my_exit(shell, NULL);
        }
        task_interpreter(input, shell);
        free(input);
    }
    return (0);
}