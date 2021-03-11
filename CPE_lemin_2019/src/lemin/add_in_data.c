/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** add_in_data
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"

char *get_name(char *line, int *len)
{
    char *name = NULL;

    for (;line[*len] != ' '; (*len) += 1);
    name = malloc(sizeof(char) * *len + 1);
    if (!name)
        return (NULL);
    name[*len] = '\0';
    for (int i = 0; i < *len; i++) {
        name[i] = line[i];
    }
    (*len) += 1;
    return (name);
}

int get_x(char *line, int *len)
{
    int x = 0;

    x = my_getnbr(&line[*len]);
    for (; line[*len] != ' '; (*len) += 1);
    (*len) += 1;
    return (x);
}

int get_y(char *line, int *len)
{
    int y = 0;

    y = my_getnbr(&line[*len]);
    return (y);
}
/*
int add_room_in_data(info_t *node, data_t *data, int room)
{
    int len = 0;
    char *name = get_name(node, &len);
    int x = get_x(node, &len);
    int y = get_y(node, &len);

    data[room].name = my_strdup(name);
    data[room].x = x;
    data[room].y = y;
    my_printf("NODE :\n");
    my_printf("name : %s\n", data[room].name);
    my_printf("x : %d\n", data[room].x);
    my_printf("y : %d\n", data[room].y);
    free (name);
    return (0);
}*/