/*
** EPITECH PROJECT, 2020
** 42sh
** File description:
** error check
*/

#include "my.h"
#include "sh.h"

int redir_name(char *file)
{
    if (my_strlen(file) == 0){
        my_dprintf(2, "Missing name for redirect.\n");
        return (1);
    }
    return (0);
}

int ambigu(int type, int *conn)
{
    if ((type == APPEND || type == WRITE) && conn[1] == 1)
        return (0);
    if ((type == READ || type == DOC) && conn[0] == 0)
        return (0);
    my_dprintf(2, "Ambiguous input redirect.\n");
    return (1);
}
