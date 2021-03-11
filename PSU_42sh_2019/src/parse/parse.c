/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse functions
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "sh.h"

int count_parts(char const *str)
{
    char **parsed = 0;
    int act_count = 0;

    for (int i = 0; str[i] != 0; i++){
        if (!my_strcmp(&str[i], "<<") || !my_strcmp(&str[i], ">>")){
            i++;
            act_count++;
            continue;
        }
        if (str[i] == '<' || str[i] == '>' || str[i] == '|')
            act_count++;
    }
    return (act_count);
}

void get_commands(char const *str, char **cmd)
{
    int i = 0;
    int j = -1;
    int prev = 0;
    int type = -1;
    int type_prev = -1;

    while (j < 0 || str[j] != 0){
        j = get_next_sep(str, j + 1);
        type = get_next_sep_type(str, j);
        if (type_prev == PIPE || type_prev < 0)
            cmd[i++] = substr(str, prev, j);
        if (type == APPEND || type == DOC)
            j++;
        type_prev = type;
        prev = j + 1;
    }
    cmd[i] = 0;
}

void get_pipes(int size, int *ptr)
{
    for (int i = 0; i < size; i++)
        pipe(ptr + 2 * i);
    ptr[size * 2] = -1;
}

cmd_t *get_parsed_command(char *str, shell_t *sh)
{
    cmd_t *cmd = malloc(sizeof(cmd_t));
    int parts = count_parts(str);

    if (!cmd)
        return (0);
    cmd->commands = malloc(sizeof(char *) * (parts + 2));
    cmd->pipes = malloc(sizeof(int) * (2 * parts + 1));
    cmd->connections = malloc(sizeof(int) * (2 * parts + 3));
    if (!cmd->commands || !cmd->pipes || !cmd->connections)
        return (0);
    get_commands(str, cmd->commands);
    get_pipes(parts, cmd->pipes);
    if (get_connections(parts, str, cmd, sh)) {
        free_cmd(cmd);
        return (0);
    }
    return (cmd);
}
