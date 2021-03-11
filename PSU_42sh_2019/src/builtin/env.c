/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** env functions
*/

#include <stdlib.h>

#include "my.h"
#include "sh.h"

char *get_env_value(char *name, char *content)
{
    int n_len = my_strlen(name);
    int c_len = my_strlen(content);
    char *ret = malloc(n_len + 1 + c_len + 1);

    if (!ret)
        return (0);
    for (int i = 0; i < n_len; i++)
        ret[i] = name[i];
    ret[n_len] = '=';
    for (int i = 0; i < c_len; i++)
        ret[n_len + 1 + i] = content[i];
    ret[n_len + 1 + c_len] = 0;
    return (ret);
}

int set_env(shell_t *sh, char *name, char *val)
{
    char *new_val = get_env_value(name, val);

    if (!new_val)
        return (1);
    sh->env = set_env_internal(sh->env, new_val, name);
    if (!sh->env)
        return (1);
    return (0);
}

int unset_env(shell_t *sh, char *name)
{
    int i = get_name_index(sh->env, name);

    if (!is_name_set(sh->env, name))
        return (0);
    free(sh->env[i]);
    for (int j = i; sh->env[j] != 0; j++)
        sh->env[j] = sh->env[j + 1];
    return (0);
}

int print_env(char **env)
{
    for (int i = 0; env[i] != 0; i++)
        my_printf("%s\n", env[i]);
    return (0);
}

char **set_env_internal(char **env, char *new_value, char *name)
{
    int cur_len = 0;
    int i = -1;
    char **tmp;

    if (!is_name_set(env, name)){
        for (; env[cur_len]; cur_len++);
        env = my_realloc(env, sizeof(char *) * (cur_len + 2));
        if (!env)
            return (0);
        i = cur_len;
        env[cur_len + 1] = 0;
    }else{
        i = get_name_index(env, name);
        free(env[i]);
    }
    env[i] = new_value;
    return (env);
}
