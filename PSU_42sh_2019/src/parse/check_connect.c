/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Connection checks
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "sh.h"
#include "my.h"

char *merge_cmd(char *org, char const *to_add)
{
    int o_len = my_strlen(org);
    int a_len = my_strlen(to_add);
    char *new_cmd = malloc(sizeof(char) * (o_len + a_len + 1));

    if (!new_cmd)
        return (0);
    for (int i = 0; i < o_len; i++)
        new_cmd[i] = org[i];
    for (int i = 0; i < a_len; i++)
        new_cmd[i + o_len] = to_add[i];
    new_cmd[o_len + a_len] = 0;
    free(org);
    return (new_cmd);
}

int check_conn(int type, int *conn)
{
    if ((type == APPEND || type == WRITE) && conn[1] != 1) {
        my_dprintf(2, "Ambiguous output redirect.\n");
        return (1);
    }
    if ((type == DOC || type == READ) && conn[0] != 0) {
        my_dprintf(2, "Ambiguous input redirect.\n");
        return (1);
    }
    return (0);
}

int write_connection_file(int type, int *conn, char *file)
{
    if (check_conn(type, conn))
        return (1);
    switch (type){
    case APPEND:
        conn[1] = open(file, O_CREAT | O_APPEND | O_WRONLY, 0644);
        break;
    case WRITE:
        conn[1] = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
        break;
    case READ:
        conn[0] = open(file, O_RDONLY);
        break;
    default:break;
    }
    if (conn[0] < 0 || conn[1] < 0){
        my_dprintf(2, "%s: %s.\n", file, strerror(errno));
        return (1);
    }
    return (0);
}

int connect_file(cmd_t *cmd, int i, int j, char const *str)
{
    int cursor = 0;
    int idx = get_next_sep(str, j + 1);
    int type = get_next_sep_type(str, j == 0 ? 0 : j - 1);
    char *file = substr(str, j + 1, idx);
    int ret = 0;

    file = trim(file);
    while (file[cursor] != 0 && file[cursor] != ' ')
        cursor++;
    if (file[cursor] == ' ')
        cmd->commands[i] = merge_cmd(cmd->commands[i], &file[cursor]);
    file[cursor] = 0;
    if (redir_name(file) || ambigu(type, cmd->connections + i * 2)){
        free(file);
        return (1);
    }
    ret = write_connection_file(type, cmd->connections + i * 2, file);
    free(file);
    return (ret);
}

int get_connections(int size, char *str, cmd_t *cmd, shell_t *sh)
{
    int i = 0;
    int j = -1;
    int type = -1;
    int strlen = my_strlen(str);
    char *file = 0;

    for (int k = 0; k < 2 * size + 3; k++)
        cmd->connections[k] = k % 2;
    cmd->connections[2 * size + 2] = -1;
    while (j < 0 || str[j] != 0){
        j = get_next_sep(str, j + 1);
        type = get_next_sep_type(str, j);
        if (type == APPEND || type == DOC)
            j++;
        if (CPIPE(type) && con_pipe((par_t) {type, cmd}, &i, str + j, sh))
            return (1);
        if (!CPIPE(type) && j + 1 <= strlen && connect_file(cmd, i, j, str))
            return (1);
    }
    return (0);
}
