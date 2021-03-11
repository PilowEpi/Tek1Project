/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** get vars from shell
*/

#include <string.h>
#include <stdlib.h>
#include "my.h"
#include "sh.h"

char *get_var_content(char *cmd, int i, shell_t *sh)
{
    char waited = ' ';
    int index = 0;
    char *var = 0;
    char *content = 0;

    if (cmd[i + 1] == '{')
        waited = '}';
    index = get_varname_index(cmd + i);
    var = substr(cmd + i, cmd[i + 1] == '{' ? 2 : 1, index);
    if ((content = get_lvar(sh->l_var, var)) || !is_name_set(sh->env, var)){
        free(var);
        return (check_par(content));
    }
    content = retrieve_value(sh->env, var);
    free(var);
    return (content);
}

char *get_var_length(char *cmd, int i, shell_t *sh)
{
    char waited = ' ';
    int index = 0;
    char *var = 0;
    char *content = 0;

    if (cmd[i + 1] == '{')
        waited = '}';
    index = get_varname_index(cmd + i);
    var = substr(cmd + i, cmd[i + 1] == '{' ? 3 : 2, index);
    if ((content = get_lvar(sh->l_var, var)) || !is_name_set(sh->env, var)){
        free(var);
        return (count_len(content));
    }
    content = retrieve_value(sh->env, var);
    free(var);
    return (content);
}

char *get_var_set(char *cmd, int i, shell_t *sh)
{
    char waited = ' ';
    int index = 0;
    char *var = 0;
    char *content = 0;

    if (cmd[i + 1] == '{')
        waited = '}';
    index = get_varname_index(cmd + i);
    var = substr(cmd + i, cmd[i + 1] == '{' ? 3 : 2, index);
    if ((content = get_lvar(sh->l_var, var)) || is_name_set(sh->env, var)){
        free(var);
        return (my_strdup("1"));
    }
    free(var);
    return (my_strdup("0"));
}

char *process_array(char *varname, char *content)
{
    size_t f_index = 0;
    size_t d_index = 0;
    int start_index = 0;
    int end_index = 0;

    if (!content)
        return (0);
    while (varname[f_index] != '[' && varname[f_index] != 0)
        f_index++;
    while (varname[d_index] != '-' && varname[d_index] != 0)
        d_index++;
    start_index = atoi(varname + f_index + 1);
    if (varname[d_index])
        end_index = atoi(varname + d_index + 1);
    else
        end_index = start_index;
    return (array_in_bounds(content, start_index - 1, end_index));
}

char *get_var_content_at(char *cmd, int i, shell_t *sh)
{
    char waited = cmd[i + 1] == '{' ? '}' : ' ';
    int index = 0;
    int a_idx = i;
    char *var = 0;
    char *content = 0;
    char *r_name = 0;

    index = get_varname_index(cmd + i);
    while (cmd[i + a_idx] != '[' && a_idx < index)
        a_idx++;
    var = substr(cmd + i, cmd[i + 1] == '{' ? 2 : 1, index);
    r_name = substr(cmd + i, cmd[i + 1] == '{' ? 2 : 1, a_idx);
    if ((content = get_lvar(sh->l_var, r_name))
        || !is_name_set(sh->env, r_name))
        return (process_array(var, check_par(content)));
    content = retrieve_value(sh->env, var);
    free(var);
    return (content);
}
