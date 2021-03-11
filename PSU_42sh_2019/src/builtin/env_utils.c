/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** env utils
*/

#include <stdlib.h>

#include "my.h"
#include "sh.h"

char **create_env(void)
{
    char **env = malloc(sizeof(char *));

    if (!env)
        return (0);
    env[0] = NULL;
    return (env);
}

char **dup_env(char **env)
{
    int size = 0;
    char **n_env = 0;

    while (env[size] != NULL)
        size++;
    n_env = malloc(sizeof(char *) * (size + 1));
    if (!n_env)
        return (0);
    n_env[size] = 0;
    for (int i = 0; i < size; i++){
        n_env[i] = my_strdup(env[i]);
        if (!n_env[i])
            return (0);
    }
    return (n_env);
}

char is_name_set(char **env, char *name)
{
    int len = my_strlen(name);

    for (int i = 0; env[i] != 0; i++){
        if (!my_strncmp(name, env[i], len) && len != 0)
            return (1);
    }
    return (0);
}

int get_name_index(char **env, char *name)
{
    int len = my_strlen(name);

    for (int i = 0; env[i] != 0; i++){
        if (!my_strncmp(name, env[i], len) && len != 0)
            return (i);
    }
    return (-1);
}

char *retrieve_value(char **env, char *name)
{
    int i = get_name_index(env, name);
    int len = my_strlen(name);

    if (i < 0)
        return ("");
    return (my_strdup(&env[i][len + 1]));
}
