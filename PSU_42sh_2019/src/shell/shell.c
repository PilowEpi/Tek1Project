/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** main shell functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

int exec_command(cmd_t *cmd, int i, shell_t *sh)
{
    int pid;
    char **av = my_str_to_word_array(cmd->commands[i]);
    int b_index = 0;

    if (!av || !av[0])
        return (!av ? 1 : free(av), 0);
    while (b_names[b_index] != 0){
        if (!my_strcmp(av[0], b_names[b_index]))
            break;
        b_index++;
    }
    if (b_names[b_index] != 0){
        dup2(cmd->connections[i * 2 + 0], 0);
        dup2(cmd->connections[i * 2 + 1], 1);
        return (call_builtin(b_index, cmd, sh, av));
    }
    if (pid = fork())
        return (wait_parent(parent(i, pid, cmd, av), sh));
    return (child(i, cmd, sh, av));
}

int send_part(char *line, int from, int to, shell_t *sh)
{
    char *sub = trim(substr(line, from, to));
    char *test = preprocess(my_strdup(sub), sh);
    cmd_t *cmd = !my_strlen(test) ? 0 : get_parsed_command(test, sh);
    int res = 0;

    if (!my_strlen(test) || !cmd || has_empty_command(cmd)){
        free(sub);
        free(test);
        return (0);
    }
    add_history(sh, test);
    for (int i = 0; cmd->commands[i] != 0; i++)
        res |= exec_command(cmd, i, sh);
    free_cmd(cmd);
    free(sub);
    free(test);
    return (res);
}

int send_sh(char *line, shell_t *sh)
{
    int last_index = 0;
    int len = my_strlen(line);
    int i = 0;
    int res = 0;

    line = backstick(line, sh);
    while (line[i] != 0) {
        if (line[i] == ';' || DOB(i, len, line, '&') || DOB(i, len, line, '|')){
            res |= send_part(line, last_index, i, sh);
            last_index = i + 1 + OFF(i, len, line, '&', '|');
        }
        if (DOB(i, len, line, '&') && sh->exit_code)
            return (res);
        if (DOB(i, len, line, '|') && !sh->exit_code)
            return (res);
        i += 1 + OFF(i, len, line, '&', '|');
    }
    res |= send_part(line, last_index, i, sh);
    return (res);
}

void exit_sh(char *line)
{
    free(line);
    if (isatty(0))
        my_printf("exit\n");
}

int shell(shell_t *sh)
{
    char *line = NULL;
    size_t buf_size = 0;
    ssize_t line_size = 0;

    do {
        if (isatty(0)) {
            my_printf("> ");
            line_size = my_getline(&line, sh);
        } else {
            line_size = getline(&line, &buf_size, stdin);
            line[line_size - 1] = '\0';
        }
        if (translate_input(line))
            continue;
        if (line_size < 0 || send_sh(line, sh))
            break;
    } while (line_size >= 0);
    exit_sh(line);
    return (0);
}
