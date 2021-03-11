/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** parse utils
*/

#include <stdlib.h>

#include "sh.h"
#include "my.h"

void free_cmd(cmd_t *cmd)
{
    for (int i = 0; cmd->commands[i] != 0; i++)
        free(cmd->commands[i]);
    free(cmd->commands);
    free(cmd->pipes);
    free(cmd->connections);
    free(cmd);
}

int get_next_sep(char const *str, int i)
{
    while (str[i] != 0){
        if (str[i] == '<'
            || str[i] == '>'
            || str[i] == '|')
            return (i);
        i++;
    }
    return (i);
}

int get_next_sep_type(char const *str, int from)
{
    int pos = get_next_sep(str, from);

    if (!my_strncmp(&str[pos], ">>", 2))
        return (APPEND);
    if (!my_strncmp(&str[pos], ">", 1))
        return (WRITE);
    if (!my_strncmp(&str[pos], "|", 1))
        return (PIPE);
    if (!my_strncmp(&str[pos], "<<", 2))
        return (DOC);
    if (!my_strncmp(&str[pos], "<", 1))
        return (READ);
    return (-1);
}

char *trim(char *str)
{
    int first = 0;
    int last = my_strlen(str) - 1;

    last = last < 0 ? 0 : last;
    while (str[last] == ' ' && last > 0)
        last--;
    while (str[first] == ' ' && str[first] != 0)
        first++;
    if (last < first) {
        str[0] = 0;
    } else {
        my_memcpy(str, str + first, last - first + 1);
        str[last - first + 1] = 0;
    }
    return (str);
}

char *substr(char const *str, int a, int b)
{
    int diff = abs(a - b);
    int st = min(a, b);
    char *nstr = malloc(diff + 1);

    if (!nstr)
        return (0);
    nstr[diff] = 0;
    for (int i = 0; i < diff; i++)
        nstr[i] = str[st + i];
    return (nstr);
}
