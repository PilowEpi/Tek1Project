/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** preprocess command
*/

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "sh.h"

char *replace_to(char *cmd, int i, shell_t *sh, char *var)
{
    char *new_cmd = 0;
    size_t len = my_strlen(cmd);
    int offset = get_varname_index(cmd + i);
    int br_off = cmd[i + 1] == '{' ? 1 : 0;

    len += my_strlen(var) - offset - br_off;
    new_cmd = malloc(sizeof(char) * (len + 1));
    for (int j = 0; j < i; j++)
        new_cmd[j] = cmd[j];
    for (int j = 0; var && var[j] != 0; j++)
        new_cmd[i + j] = var[j];
    for (int j = i + my_strlen(var); j < len; j++)
        new_cmd[j] = cmd[i++ + br_off + offset];
    new_cmd[len] = 0;
    free(var);
    return (new_cmd);
}

char *process_var(char *cmd, int i, shell_t *sh)
{
    char *to = 0;
    int (*parsers[])(char *) = {ucp_var, ucp_len, ucp_set, ucp_array, 0};
    char *(*replace[])(char *, int, shell_t *) = {
        get_var_content, get_var_length, get_var_set, get_var_content_at, 0};
    char *from[] = {"$*", "$0", "$1", "$2", "$3", "$4", "$5", 0};
    char *fto[] = {"$argv", "$argv[0]", "$argv[1]", "$argv[2]", "$argv[3]",
        "$argv[4]", "$argv[5]"};

    for (int j = 0; from[j] != 0; j++)
        if (!my_strncmp(from[j], cmd + i, 2))
            return (replace_to(cmd, i, sh, get_var_content_at(fto[j], 0, sh)));
    for (int j = 0; parsers[j] != 0; j++)
        if (parsers[j](cmd + i))
            return (replace_to(cmd, i, sh, replace[j](cmd, i, sh)));
    return (replace_to(cmd, i, sh, 0));
}

char *preprocess(char *cmd, shell_t *sh)
{
    int k = 0;

    for (int i = 0; cmd && cmd[i] != 0 && k < 100000; i++, k++){
        if (cmd[i] != '$' && cmd[i] != '*')
            continue;
        if (cmd[i] == '$'){
            cmd = process_var(cmd, i, sh);
            i = 0;
        }
        if (!cmd)
            break;
        if (cmd[i] == '*'){
            cmd = process_star(cmd, i, sh);
            i = 0;
        }
    }
    return (cmd);
}
