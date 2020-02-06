/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** get_index_of_env
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int get_index_of_env(shell_t *shell, char *to_unset)
{
    chain_t *tmp = shell->env.head;
    int i = 0;

    while ((tmp != NULL) && (my_strcmp(to_unset, tmp->name_env) != 0)) {
        tmp = tmp->next;
        i++;
    }
    if (tmp == NULL)
        return (-1);
    return (i);
}
