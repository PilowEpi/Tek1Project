/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** shell utils functions
*/

#include <stdlib.h>

#include "my.h"
#include "sh.h"

char *get_filepath(char *name, char *path)
{
    int l_name = my_strlen(name);
    int l_path = my_strlen(path);
    int offset = path[l_path - 1] == '/' ? 0 : 1;
    char *filepath = malloc(l_path + offset + l_name + 1);

    for (int i = 0; i < l_path; i++)
        filepath[i] = path[i];
    if (offset)
        filepath[l_path] = '/';
    for (int i = 0; i < l_name; i++)
        filepath[l_path + offset + i] = name[i];
    filepath[l_name + offset + l_path] = '\0';
    return (filepath);
}

void check_script(char **av, char **envp)
{
    size_t len = my_strlen(av[0]) - 1;
    size_t av_len = 0;
    char **cpy = 0;

    if (len < 3)
        return;
    if (av[0][len] != 'h' || av[0][len - 1] != 's'
        || av[0][len - 2] != '.')
        return;
    while (av[av_len])
        av_len++;
    cpy = malloc(sizeof(char *) * (av_len + 2));
    for (int i = 0; i < av_len; i++)
        cpy[i + 1] = av[i];
    cpy[0] = my_strdup("./42sh");
    cpy[av_len + 1] = 0;
    main(av_len + 1, cpy, envp);
    exit(0);
}

int has_empty_command(cmd_t *cmd)
{
    for (int i = 0; cmd->commands[i] != 0; i++){
        if (my_strlen(cmd->commands[i]) == 0){
            my_dprintf(2, "Invalid null command.\n");
            free_cmd(cmd);
            return (1);
        }
    }
    return (0);
}
