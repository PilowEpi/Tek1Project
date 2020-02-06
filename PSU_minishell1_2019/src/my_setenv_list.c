/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_setenv_list
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

void my_setenv_list(shell_t *shell, char **args)
{
    chain_t *new_env = malloc(sizeof(chain_t));
    chain_t *save_env = shell->env.head;

    if (new_env == NULL)
        return;
    else if (get_index_of_env(shell, args[1]) != -1) {
        my_unset_list(shell, args[1]);
        save_env = shell->env.head;
    }
    new_env->name_env = args[1];
    new_env->env_value = args[2];
    new_env->next = save_env;
    shell->env.head = new_env;
}