/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_value_of_env
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

char *get_value_of_env(shell_t *shell, int index)
{
    char *result = NULL;
    chain_t *tmp = shell->env.head;
    int i = 0;

    while ((tmp != NULL) && i < index) {
        tmp = tmp->next;
        i++;
    }
    if (tmp->env_value != NULL)
        result = my_strdup(tmp->env_value);
    return (result);
}