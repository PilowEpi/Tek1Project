/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my.h"
#include "sh.h"

void handle_sig(int signal)
{
    char *error;

    if (signal == SIGINT){
        my_printf("\n> ");
    }else{
        error = strsignal(signal);
        write(2, error, my_strlen(error));
    }
}

int script(shell_t *sh, int ac, char **av)
{
    int fd = 0;

    if (ac < 2 || access(av[1], X_OK))
        return (0);
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (0);
    dup2(fd, 0);
    return (1);
}

int create_shell(shell_t *sh, char **env)
{
    if (env == NULL)
        sh->env = create_env();
    else
        sh->env = dup_env(env);
    if (!sh->env)
        return (84);
    sh->streams[0] = dup(0);
    sh->streams[1] = dup(1);
    sh->exit_code = 0;
    sh->l_var = locale_variables_init(sh);
    sh->dirs = init_dirs(sh);
    sh->alias = init_alias();
    sh->history = lld_init();
    init_cd(sh->env);
    return (0);
}

int main(int ac, char **av, char **env)
{
    shell_t sh;

    signal(SIGINT, handle_sig);
    sh.original_args = av;
    if (create_shell(&sh, env))
        return (84);
    sh.script = script(&sh, ac, av);
    shell(&sh);
    for (int i = 0; sh.env[i] != 0; i++)
        free(sh.env[i]);
    free(sh.env);
    close(sh.streams[0]);
    close(sh.streams[1]);
    free_cd();
    malloc(-1);
    return (sh.exit_code);
}
