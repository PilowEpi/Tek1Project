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

// alpha + num + _ + 0 et 64 passe pas + 123 et 127 passe pas

int is_alpha(char c)
{
    if (is_num(c)) {
        return (1);
    } else if (('a' <= c && c <= 'z') ||
        ('A' <= c && c <= 'Z')) {
        return (2);
    }
    return (0);
}

int verify_value_env(const char *value)
{
    if (is_alpha(value[0]) != 2){
        my_printf("setenv: Variable name must begin with a letter.\n");
        return (84);
    }
    for (int i = 1; value[i] != '\0'; i++) {
        if (!is_alpha(value[i])) {
            my_printf("setenv: Variable name must");
            my_printf(" contain alphanumeric characters.\n");
            return (84);
        }
    }
    return (0);
}

void my_setenv_list(shell_t *shell, char **args)
{
    chain_t *new_env = malloc(sizeof(chain_t));
    chain_t *save_env = shell->env.head;

    if (new_env == NULL || verify_value_env(args[1]))
        return;
    else if (get_index_of_env(shell, args[1]) != -1) {
        my_unset_list(shell, args[1]);
        save_env = shell->env.head;
    }
    new_env->name_env = my_strdup(args[1]);
    new_env->env_value = my_strdup(args[2]);
    new_env->next = save_env;
    shell->env.head = new_env;
}