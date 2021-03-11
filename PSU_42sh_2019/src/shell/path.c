/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** path lookup
*/

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

static int get_count(char *path)
{
    int count = 1;

    for (int i = 0; path[i] != 0; i++)
        if (path[i] == ':')
            count++;
    return (count);
}

static char **malloc_paths(char *path)
{
    int count = get_count(path);
    char **paths = malloc(sizeof(char *) * (count + 1));
    int j = 0;
    int k = 0;

    if (!paths)
        return (0);
    for (int i = 0; path[i] != 0; i++, k++){
        if (path[i] == ':'){
            paths[j] = malloc(k + 1);
            j++;
            k = -1;
        }
    }
    paths[j] = malloc(k + 1);
    paths[count] = 0;
    for (int i = 0; i < j + 1; i++)
        if (!paths[j])
            return (0);
    return (paths);
}

char **get_paths(char **env)
{
    char *path = retrieve_value(env, "PATH");
    char **paths = malloc_paths(path);
    int j = 0;
    int k = 0;

    if (!paths)
        return (0);
    for (int i = 0; path[i] != 0; i++, k++){
        paths[j][k] = path[i];
        if (path[i] == ':'){
            paths[j][k] = 0;
            j++;
            k = -1;
        }
    }
    free(path);
    paths[j][k] = 0;
    return (paths);
}

void try_exec(char *path, char **av, char **envp)
{
    if (!access(path, X_OK))
        execve(path, av, envp);
    if (!access(path, F_OK)){
        my_dprintf(2, av[0]);
        errno == 1 ? my_dprintf(2, ": Permission denied.\n") : 0;
        errno == 2 ? my_dprintf(2, ": Command not found.\n") : 0;
        errno == 8 ? my_dprintf(2, ": Exec format error. Wrong Architecture.\n")
            : 0;
        errno == 13 ? my_dprintf(2, ": Permission denied.\n") : 0;
        errno == 40 ? my_dprintf(2, ": Too many levels of symbolic links.\n")
            : 0;
        exit(-1);
    }
}
