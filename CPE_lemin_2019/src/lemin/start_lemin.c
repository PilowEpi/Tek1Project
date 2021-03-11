/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** start_lemin
*/

#include <stdlib.h>

#include "lemin.h"

int start_lemin(void)
{
    lemin_t lemin;

    lemin.anthill = malloc(sizeof(room_t *));
    lemin.anthill[0] = NULL;
    if (get_info(&lemin))
        return (84);
    if (start_error(&lemin))
        return (84);
    solve(&lemin);
    for (int i = 0; lemin.anthill[i] != NULL; i++){
        free(lemin.anthill[i]->next);
        free(lemin.anthill[i]->name);
        free(lemin.anthill[i]);
    }
    free(lemin.anthill);
    return (0);
}
