/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** connections between pipes
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

char **get_array_doc(char *delim, shell_t *sh)
{
    ssize_t line_size = 0;
    char *line = 0;
    lld_t *array = lld_init();
    char **res;

    do {
        if (isatty(0))
            my_printf("? ");
        line_size = my_getline(&line, sh);
        if (line_size < 0)
            break;
        if (!my_strcmp(line, delim))
            break;
        lld_insert(array, (u64) array->data, line);
        line = 0;
    } while (line_size >= 0);
    res = (char **) lld_lld_to_tab(array);
    lld_free(array);
    return (res);
}

char *get_document(char *delim, shell_t *sh)
{
    size_t len = 0;
    char *res = 0;
    char **array = get_array_doc(delim, sh);

    if (!array)
        return (0);
    for (int i = 0; array[i] != 0; i++)
        len += my_strlen(array[i]) + 1;
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (0);
    res[0] = 0;
    for (int i = 0; array[i] != 0; i++) {
        strcat(res, array[i]);
        strcat(res, "\n");
    }
    res[len] = 0;
    return (res);
}

int connect_doc(int *conn, int *pipes, char *str, shell_t *sh)
{
    int idx = get_next_sep(str, 1);
    char *sub = substr(str, 0, idx);
    char *res = 0;

    if (!sub)
        return (1);
    sub = trim(sub);
    if (!(res = get_document(sub, sh)))
        return (1);
    conn[0] = pipes[0];
    write(pipes[1], res, my_strlen(res));
    close(pipes[1]);
    return (0);
}

int con_pipe(par_t par, int *i, char *str, shell_t *sh)
{
    static int offset = 0;

    if (par.type == DOC) {
        offset++;
        return (connect_doc(par.cmd->connections + *i * 2,
            par.cmd->pipes + *i * 2, str + 1, sh));
    }
    if (par.cmd->connections[*i * 2 + 1] != 1
        || par.cmd->connections[*i * 2 + 2] != 0) {
        my_dprintf(2, "Ambiguous %sput redirect.\n",
            par.cmd->connections[2] != 0 ? "in" : "out");
        return (1);
    }
    par.cmd->connections[*i * 2 + 1] = par.cmd->pipes[(*i + offset) * 2 + 1];
    par.cmd->connections[*i * 2 + 2] = par.cmd->pipes[(*i + offset) * 2 + 0];
    *i += 1;
    return (0);
}
