/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** print_env
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int print_list_env(list_t *env)
{
    chain_t *tmp = env->head;

    while (tmp != NULL) {
        my_printf("%s=", tmp->name_env);
        if (tmp->env_value != NULL)
            my_printf("%s", tmp->env_value);
        my_printf("\n");
        tmp = tmp->next;
    }
    return (0);
}

int print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++)
        my_printf("%s\n", env[i]);
    return (0);
}