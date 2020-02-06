/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** my_unset_list
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

int my_unset_list(shell_t *shell, char *to_unset)
{
    int index = get_index_of_env(shell, to_unset);
    chain_t *tmp = shell->env.head;
    chain_t *save = tmp->next;

    if (index > 0) {
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
            save = tmp->next;
        }
        tmp->next = tmp->next->next;
        free(save->name_env);
        free(save->env_value);
        free(save);
    } else if (index != -1) {
        shell->env.head = save;
        free(tmp->name_env);
        free(tmp->env_value);
        free(tmp);
    }
    return (0);
}