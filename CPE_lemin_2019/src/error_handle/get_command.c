/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** get_info
*/

#include <stdlib.h>
#include <stdio.h>

#include "lemin.h"
#include "my.h"

int add_item_in_list(char *info, lemin_t *lemin)
{
    static char tunnels;

    if (!tunnels && is_pipe(info)){
        my_printf("#tunnels\n");
        tunnels ^= 1;
    }
    if (remove_comment(info) == 84)
        return (84);
    if (is_comment(info) || is_command(info) == 2){
        return (0);
    }
    if (is_room(info) || is_command(info))
        return (add_room(info, lemin));
    else if (is_pipe(info))
        return (add_pipe(info, lemin));
    free(info);
    return (-1);
}

int get_ants(lemin_t *lemin)
{
    char *line = NULL;
    size_t read = 0;
    size_t len = 0;
    ssize_t nread = 0;

    nread = getline(&line, &len, stdin);
    if (nread == 0 || nread == -1)
        return (1);
    lemin->nb_ant = my_getnbr(line);
    my_printf("#number_of_ants\n%d\n", lemin->nb_ant);
    free(line);
    if (lemin->nb_ant <= 0)
        return (1);
    return (0);
}

int read_stdin(lemin_t *lemin)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;

    if (get_ants(lemin))
        return (84);
    my_printf("#rooms\n");
    while (nread != -1 && nread < 1000) {
        nread = getline(&line, &len, stdin);
        if (nread < 0)
            break;
        (nread > 0) ? line[nread - 1] = 0 : 0;
        if (add_item_in_list(my_strdup(line), lemin) == -1)
            return (84);
    }
    free(line);
    if (nread >= 1000)
        return (84);
    return (0);
}

int get_info(lemin_t *lemin)
{
    if (read_stdin(lemin))
        return (84);
    return (0);
}
