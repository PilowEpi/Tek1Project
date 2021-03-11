/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins wrapper
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "my.h"
#include "sh.h"

int call_builtin(int idx, cmd_t *cmd, shell_t *sh, char **av)
{
    int ac = 0;
    int res = 0;

    while (av[ac] != 0)
        ac++;
    res = builtins[idx](ac, av, sh);
    dup2(sh->streams[0], 0);
    dup2(sh->streams[1], 1);
    for (int j = 0; av[j] != 0; j++)
        free(av[j]);
    free(av);
    return (res);
}

int end_cd(shell_t *sh)
{
    char *cur = getcwd(0, 0);
    int ret = set_env(sh, "PWD", cur);
    char *owd = retrieve_value(sh->env, "OLDPWD");

    if (owd && *owd)
        add_locale_var("owd", my_strdup(owd), sh->l_var);
    add_locale_var("cwd", my_strdup(cur), sh->l_var);
    update_dirs_cwd(sh);
    free(cur);
    return (ret);
}

void init_cd(char **env)
{
    old_pwd = retrieve_value(env, "OLDPWD");
}

void free_cd(void)
{
    free(old_pwd);
}

int exec_cd(char *path, shell_t *sh)
{
    char *pwd = getcwd(0, 0);

    if (!my_strcmp(path, "-")){
        if (!old_pwd)
            my_dprintf(2, ": No such file or directory.\n");
        if (old_pwd && !chdir(old_pwd))
            free(old_pwd), old_pwd = pwd;
        if (old_pwd && set_env(sh, "OLDPWD", old_pwd))
            return (1);
        return (end_cd(sh));
    }
    if (check_cd(path))
        return (0);
    if (!chdir(path))
        free(old_pwd), old_pwd = pwd;
    if (set_env(sh, "OLDPWD", old_pwd))
        return (1);
    return (end_cd(sh));
}
