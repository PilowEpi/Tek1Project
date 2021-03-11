/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch reading enemy loots
*/

#include <stdlib.h>

#include "rpg.h"

int set_new_entity_loot(loot_table_t *loot, dfile_t *data, int *i)
{
    loot->id = data->data[*i + 1];
    loot->quantity = data->data[*i + 2];
    loot->prob = data->data[*i + 3];
    return (0);
}

int add_loot(entity_t *entity, dfile_t *data, int *i)
{
    loot_table_t **old = entity->loot_table;
    loot_table_t **new;
    int count = 0;

    for (; old && old[count]; count++);
    new = malloc(sizeof(loot_t *) * (count + 2));
    if (!new)
        return (1);
    for (int i = 0; i < count; i++)
        new[i] = old[i];
    new[count] = malloc(sizeof(loot_t));
    if (!new[count] || set_new_entity_loot(new[count], data, i)) {
        free(old);
        return (-(data->data_size));
    }
    new[count + 1] = 0;
    entity->loot_table = new;
    if (old)
        free(old);
    return (4);
}