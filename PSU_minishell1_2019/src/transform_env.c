/*
** EPITECH PROJECT, 2020
** PSU_minishell1_2019
** File description:
** transform_env
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int get_length_of_env(list_t *env)
{
    chain_t *tmp = env->head;
    int length = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        length++;
    }
    return (length);
}

void malloc_env(char **result, list_t *env)
{
    chain_t *tmp = env->head;
    int index = 0;
    int len_name = 0;
    int len_val = 0;

    while (tmp != NULL) {
        len_name = my_strlen(tmp->name_env);
        len_val = my_strlen(tmp->env_value);
        result[index] = malloc(len_name + len_val + 2);
        tmp = tmp->next;
        index++;
    }
}

void fill_env(char **result, list_t *env)
{
    chain_t *tmp = env->head;
    int index = 0;
    int env_index = 0;

    while (tmp != NULL) {
        for (int i = 0; i < my_strlen(tmp->name_env); i++, env_index++)
            result[index][env_index] = tmp->name_env[i];
        result[index][env_index] = '=';
        env_index++;
        for (int j = 0;tmp->env_value && j < my_strlen(tmp->env_value);
            j++, env_index++)
            result[index][env_index] = tmp->env_value[j];
        result[index][env_index] = '\0';
        tmp = tmp->next;
        env_index = 0;
        index++;
    }
}

char **transform_env(list_t *env)
{
    int len = get_length_of_env(env);
    char **result = malloc((sizeof(char *)) * (len + 1));

    if (result == NULL)
        return (NULL);
    result[len] = NULL;
    malloc_env(result, env);
    fill_env(result, env);
    return (result);
}