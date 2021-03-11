/*
** EPITECH PROJECT, 2020
** my_int_to_str
** File description:
** Cast int to str
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void *my_realloc(void *al, int size)
{
    void *mal = realloc(al, size);
    int i = 0;

    if (!mal)
        exit(84);
    for (lld_t *mv = malloc_list->next; mv; mv = mv->next, i++){
        if (mv->data == al){
            lld_pop_my(malloc_list, i);
            break;
        }
    }
    lld_insert_my(malloc_list, 0, mal);
    return (mal);
}

void *my_malloc(u64 size)
{
    void *mal;

    !malloc_list ? malloc_list = lld_init_my() : 0;
    if (size == -1 && malloc_list){
        while (malloc_list->data)
            free(lld_pop_my(malloc_list, 0));
        free(malloc_list);
        return (0);
    }
    mal = malloc(size);
    if (!mal)
        exit(84);
    lld_insert_my(malloc_list, 0, mal);
    return (mal);
}

void my_free(void *mal)
{
    int i = 0;

    for (lld_t *mv = malloc_list->next; mv; mv = mv->next, i++){
        if (mv->data == mal){
            free(lld_pop_my(malloc_list, i));
            return;
        }
    }
    free(mal);
}
