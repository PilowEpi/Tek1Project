/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** backstick prosesibng
*/

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "sh.h"

int ucp_backstick(char *str);

char *backstick_backstr(lld_t *lld, int size, int pid)
{
    char *str = malloc(sizeof(char) * (size+1));
    int str_p = 0;
    int stat = 0;

    waitpid(pid, &stat, 0);
    if (!str)
        exit(84);
    for (lld_t *mv = lld->next; mv; mv = mv->next)
        for (int i = 0; i < 4096 && str_p < size ; i++, str_p++)
            str[str_p] = ((char *)mv->data)[i];
    str[str_p] = 0;
    lld_free(lld);
    return (str);
}

char *mem_cpy(char *str, int size)
{
    char *dest = malloc(size);

    if (!dest)
        exit(84);
    for (int i = 0; i < size; i++)
        dest[i] = str[i] == '\n' ? ' ' : str[i];
    return (dest);
}

char *prosess_back(char *line, shell_t *sh)
{
    int pip[2];
    int pid = 0;
    int stat = 0;
    char buf[4096];
    lld_t *lld = lld_init();
    int size = 0;

    if (pipe(pip) == -1)
        exit(84);
    dup2(pip[1], 1);
    if ((pid = fork()) == 0)
        send_sh(line+1, sh), exit(0);
    dup2(sh->streams[1], 1);
    close(pip[1]);
    do {
        stat = read(pip[0], buf, 4096);
        size += stat;
        lld_insert(lld, (u64)lld->data, mem_cpy(buf, stat));
    } while (stat == 4096);
    return (backstick_backstr(lld, size, pid));
}

char *my_backstick_cat(char *stra, char *strb, char *strc)
{
    char *dest = malloc(my_strlen(stra)+my_strlen(strb)+my_strlen(strc)+1);
    int i = 0;

    if (!dest)
        exit(84);
    for (int j = 0; stra[j]; j++, i++)
        dest[i] = stra[j];
    for (int j = 0; strb[j]; j++, i++)
        dest[i] = strb[j];
    for (int j = 0; strc[j]; j++, i++)
        dest[i] = strc[j];
    dest[i] = 0;
    return (dest);
}

char *backstick(char *line, shell_t *sh)
{
    char ***tab;
    char *str = "";
    int nb = ucp(line, "***", ucp_arguments, ucp_backstick, ucp_arguments);

    nb == 0 ? str = line : 0;
    for (; nb > 0; nb--){
        tab = ucp_tab(line, "***", ucp_arguments, ucp_backstick, ucp_arguments);
        line[my_strlen(tab[0][0])] = 0;
        tab[0][1][my_strlen(tab[0][1])-1] = 0;
        str = my_backstick_cat(prosess_back(tab[0][1], sh), tab[0][2], str);
        if (nb == 1)
            str = my_backstick_cat(tab[0][0], "", str);
        ucp_free(tab);
    }
    return (str);
}
