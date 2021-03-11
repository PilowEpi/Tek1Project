/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_core
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

void print_list(list_t *list)
{
    chain_t *tmp = list->head;

    while (tmp != NULL) {
        my_printf("%d ", tmp->nbr);
        tmp = tmp->next;
    }
    my_printf("\n");
}

void my_free_list(list_t *list)
{
    chain_t *tmp = list->head;
    chain_t *to_free;

    while (tmp != NULL) {
        to_free = tmp;
        tmp = tmp->next;
        free(to_free);
    }
}

void create_list(int ac, char **av, list_t *list)
{
    chain_t *prev = NULL;
    chain_t *chain = malloc(sizeof(chain_t));

    list->length = ac - 1;
    list->head = chain;
    list->pos_lower = 0;
    for (int i = 1; i < ac; i++) {
        chain->nbr = my_getnbr(av[i]);
        chain->prev = prev;
        prev = chain;
        if (i != ac - 1) {
            chain->next = malloc(sizeof(chain_t));
            chain = chain->next;
        }
    }
    list->end = chain;
    chain->next = NULL;
}

void initialize(list_t *list)
{
    list->head = NULL;
    list->end = NULL;
    list->length = 0;
    list->pos_lower = 0;
}

int start_sort(int ac, char **av)
{
    list_t la;
    list_t lb;
    buffer_t buff;

    buff.buffer = malloc(50000000);
    buff.index = 0;
    buff.buffer = reset_my_buffer(buff.buffer, sizeof(buff.buffer));
    create_list(ac, av, &la);
    initialize(&lb);
    sorting_algo(&la, &lb, &buff);
    my_free_list(&la);
    my_free_list(&lb);
    free(buff.buffer);
    return (0);
}