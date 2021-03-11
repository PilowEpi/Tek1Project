/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch reading items
*/

#include <stdlib.h>

#include "rpg.h"

int add_item(e_bank_t *bank, int *item_size, dfile_t *data, int *i)
{
    loot_t **old = bank->loot;
    loot_t **new = malloc(sizeof(loot_t *) * (*item_size + 2));

    if (!new)
        return (1);
    for (int i = 0; i < *item_size; i++)
        new[i] = old[i];
    new[*item_size] = malloc(sizeof(loot_t));
    new[*item_size]->id = *item_size;
    new[*item_size]->body = NULL;
    new[*item_size + 1] = 0;
    if (!new[*item_size]) {
        free(old);
        return (-(data->data_size));
    }
    *item_size += 1;
    bank->loot = new;
    free(old);
    return (2);
}