/*
** EPITECH PROJECT, 2020
** PSU_42sh_2019
** File description:
** Tab exit
*/

#include <stdio.h>
#include "sh.h"

void exit_completion(char *strs, lld_t *posi, lld_t *result, lld_t *str)
{
    free(strs);
    lld_free(posi);
    lld_free(result);
    printf("> ");
    for (lld_t *mv = str->next; mv; mv = mv->next)
        printf("%c", mv->data);
}

void lld_sort_dest(lld_t *result)
{
    lld_sort(result, my_strcmp);
    int i = 0;
    for (lld_t *mv = result->next; mv && mv->next; mv = mv->next, i++){
        while (mv->next && !my_strcmp(mv->data, mv->next->data))
            my_free(lld_pop(result, i+1));
    }
}
