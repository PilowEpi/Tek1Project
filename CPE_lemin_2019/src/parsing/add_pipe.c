/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** add_pipe
*/

#include <stddef.h>
#include <stdlib.h>

#include "lemin.h"
#include "my.h"

room_t *get_room(char *name, room_t **room_list)
{
    for (int i = 0; room_list[i]; i++) {
        if (my_strcmp(name, room_list[i]->name) == 0)
            return (room_list[i]);
    }
    return (NULL);
}

int add_connection(char *from, char *to, room_t **room_list)
{
    room_t *first = get_room(from, room_list);
    room_t *second = get_room(to, room_list);
    room_t **new_list = 0;
    int size = 0;

    if (!first || !second)
        return (-1);
    for (; first->next[size] != 0; size++);
    if (!(new_list = malloc(sizeof(room_t *) * (size + 2))))
        return (-1);
    for (int i = 0; i < size; i++)
        new_list[i] = first->next[i];
    new_list[size] = second;
    new_list[size + 1] = 0;
    free(first->next);
    first->next = new_list;
    return (0);
}

int get_names(char *info, char **first, char **second)
{
    int i = 0;
    int len = 0;

    for (; info[len] != 0 && info[len] != ' ' && info[len] != '#'; len++);
    for (; info[i] != 0 && info[i] != '-'; i++);
    *first = malloc(sizeof(char) * (i + 1));
    *second = malloc(sizeof(char) * (len - i + 1));
    if (!*first || !*second)
        return (-1);
    (*first)[i] = 0;
    (*second)[len - i] = 0;
    for (int j = 0; j < i; j++)
        (*first)[j] = info[j];
    for (int j = 0; j < len - i; j++)
        (*second)[j] = info[i + j + 1];
    return (0);
}

int add_pipe(char *info, lemin_t *lemin)
{
    char *first;
    char *second;

    if (get_names(info, &first, &second) < 0)
        return (-1);
    if (add_connection(first, second, lemin->anthill) < 0){
        free(first);
        free(second);
        return (-1);
    }
    if (add_connection(second, first, lemin->anthill) < 0){
        free(first);
        free(second);
        return (-1);
    }
    my_printf("%s-%s\n", first, second);
    free(first);
    free(second);
    free(info);
    return (0);
}
