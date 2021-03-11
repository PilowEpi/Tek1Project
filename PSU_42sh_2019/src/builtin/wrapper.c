/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** builtins wrapper
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "sh.h"
#include "my.h"

int wrap_setenv(int ac, char **av, shell_t *sh)
{
    if (ac == 1){
        print_env(sh->env);
        return (0);
    }else if (ac > 3){
        my_dprintf(2, "setenv: Too many arguments.\n");
        return (0);
    }
    if (check_setenv(av))
        return (0);
    if (ac == 2)
        return (set_env(sh, av[1], ""));
    return (set_env(sh, av[1], av[2]));
}

int wrap_unsetenv(int ac, char **av, shell_t *sh)
{
    if (ac == 1){
        my_dprintf(2, "unsetenv: Too few arguments.\n");
        return (0);
    }
    for (int i = 1; i < ac; i++)
        unset_env(sh, av[i]);
    return (0);
}

int wrap_env(int ac, char **av, shell_t *sh)
{
    char broken_at = 0;
    char **env = sh->env;

    for (int i = 1; i < ac; i++){
        if (!my_strcmp(av[i], "-i")){
            env = create_env();
        }else{
            broken_at = i;
            break;
        }
        if (!env)
            return (1);
    }
    if (!broken_at)
        return (print_env(env));
    else
        return (exec_env_from(env, av, ac, broken_at));
}

int wrap_cd(int ac, char **av, shell_t *sh)
{
    char *home;
    int ret;

    if (ac > 2){
        my_dprintf(2, "cd: Too many arguments.\n");
        return (0);
    }
    if (ac == 1){
        if (!is_name_set(sh->env, "HOME")){
            my_dprintf(2, "cd: No home directory.\n");
            return (0);
        }
        home = retrieve_value(sh->env, "HOME");
        if (!home)
            return (1);
        ret = exec_cd(home, sh);
        free(home);
        return (ret);
    }
    return (exec_cd(av[1], sh));
}

int wrap_exit(int ac, char **av, shell_t *sh)
{
    if (ac == 1)
        return (1);
    if (ac != 2 || !is_num(av[1][0])){
        fprintf(stderr, "exit: Expression Syntax.\n");
        sh->exit_code = 1;
        return (0);
    }
    if (!my_str_isnum(av[1])) {
        fprintf(stderr, "exit: Badly formed number.\n");
        sh->exit_code = 1;
        return (0);
    }
    sh->exit_code = (unsigned char) my_getnbr(av[1]);
    return (1);
}
