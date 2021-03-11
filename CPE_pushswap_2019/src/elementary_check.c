/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** elemetary_check
*/

#include "pushswap.h"
#include <stddef.h>

int is_sort(list_t *list)
{
    chain_t *tmp = list->head;
    int count = 0;
    int stock = tmp->nbr;

    while (tmp != NULL) {
        if (stock > tmp->nbr)
            count++;
        stock = tmp->nbr;
        tmp = tmp->next;
    }
    if (count == 0)
        return (0);
    return (1);
}

void get_lower(list_t *list)
{
    chain_t *tmp = list->head;
    int lower = tmp->nbr;
    int pos_lower = 0;

    tmp = tmp->next;
    for (int i = 0; i != list->length - 1; i++) {
        if (lower > tmp->nbr) {
            pos_lower = i + 1;
            lower = tmp->nbr;
        }
        tmp = tmp->next;
    }
    list->pos_lower = pos_lower;
}