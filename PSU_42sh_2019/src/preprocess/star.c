/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** star preprocess
*/

#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "sh.h"

char **get_filelist(char *cmd, int i, shell_t *sh)
{
    char *pattern = get_pattern(cmd, i);
    char *folder = get_folder(cmd, i);
    char *append = get_append(cmd, i);
    DIR *dir = opendir(folder);
    lld_t *lld = lld_init();
    struct dirent *read = 0;
    char **res = 0;

    if (!pattern || !folder || !dir || !lld)
        return (0);
    while (read = readdir(dir))
        if (match(read->d_name, pattern) && (read->d_name[0] != '.'
            || pattern[0] == '.'))
            lld_insert(lld, (u64) lld->data,
            merge_dir(folder, read->d_name, append));
    closedir(dir);
    lld_sort(lld, &my_strcmp);
    res = (char **) lld_lld_to_tab(lld);
    lld_free(lld);
    return (res);
}

char *get_filelist_str(char *cmd, int i, shell_t *sh)
{
    char **array = get_filelist(cmd, i, sh);
    size_t len = 0;
    char *res = 0;

    if (!array || !array[0])
        return (my_strdup(""));
    for (int i = 0; array[i] != 0; i++)
        len += my_strlen(array[i]) + 1;
    res = malloc(sizeof(char) * (len + 1));
    if (!res)
        return (0);
    res[0] = 0;
    for (int i = 0; array[i] != 0; i++) {
        strcat(res, array[i]);
        if (array[i + 1])
            strcat(res, " ");
    }
    res[len] = 0;
    return (res);
}

int get_start(char *cmd, int i)
{
    int start = i;

    while (cmd[start] != ' ' && start > 0)
        start--;
    return (start);
}

int get_end(char *cmd, int i)
{
    int end = i;

    while (cmd[end] != ' ' && cmd[end] != 0)
        end++;
    return (end);
}

char *process_star(char *cmd, int i, shell_t *sh)
{
    int start = get_start(cmd, i);
    int end = get_end(cmd, i);
    char *replace = get_filelist_str(cmd, i, sh);
    char *new_cmd = 0;

    if (!replace)
        return (cmd);
    new_cmd = malloc(sizeof(char) * (start + 2 +
        my_strlen(replace) + my_strlen(cmd) - end));
    if (!new_cmd)
        return (0);
    start++;
    for (int j = 0; j < start; j++)
        new_cmd[j] = cmd[j];
    for (int j = 0; j < my_strlen(replace); j++)
        new_cmd[start + j] = replace[j];
    for (int j = 0; j < my_strlen(cmd) - end; j++)
        new_cmd[start + my_strlen(replace) + j] = cmd[end + j];
    new_cmd[start + my_strlen(replace) + my_strlen(cmd) - end] = 0;
    return (new_cmd);
}
