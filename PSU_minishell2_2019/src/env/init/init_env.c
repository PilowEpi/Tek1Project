/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** init_env
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int index_of_env(char *env)
{
    int index = 0;

    for (int i = 0; env[i] != '\0' && env[i] != '='; i++) {
        index++;
    }
    return (index);
}

char *get_env_name(char *env)
{
    int len_index = index_of_env(env);
    char *env_name = malloc(sizeof(char) * (len_index + 1));

    if (env_name == NULL)
        return (NULL);
    env_name[len_index] = '\0';
    for (int i = 0; i < len_index; i++) {
        env_name[i] = env[i];
    }
    return (env_name);
}

char *get_env_value(char *env)
{
    int len_index = index_of_env(env);
    char *env_value = my_strdup(&env[len_index + 1]);

    return (env_value);
}

int init_env(char **envp, list_t *env)
{
    chain_t *chain = malloc(sizeof(chain_t));

    if (chain == NULL)
        return (84);
    env->head = chain;
    for (int i = 0; envp[i] != NULL; i++) {
        chain->name_env = get_env_name(envp[i]);
        chain->env_value = get_env_value(envp[i]);
        if (chain->name_env == NULL || chain->env_value == NULL)
            return (84);
        if (envp[i + 1] != NULL) {
            chain->next = malloc(sizeof(chain_t));
            chain = chain->next;
        }
    }
    chain->next = NULL;
    return (0);
}