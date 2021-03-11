/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Copy an entity
*/

#include <stdlib.h>

#include "rpg.h"

sfConvexShape **copy_body(sfConvexShape **body)
{
    sfConvexShape **copy;
    int i = 0;

    for (; body[i]; i++);
    copy = malloc(sizeof(sfConvexShape *) * (i + 1));
    if (!copy)
        return (0);
    for (i = 0; body[i]; i++)
        copy[i] = sfConvexShape_copy(body[i]);
    copy[i] = 0;
    return (copy);
}

loot_table_t *copy_loot(loot_table_t *loot)
{
    loot_table_t *copy = malloc(sizeof(loot_table_t));

    if (!copy)
        return (0);
    copy->id = loot->id;
    copy->prob = loot->prob;
    copy->quantity = loot->quantity;
    return (copy);
}

loot_table_t **copy_loottable(loot_table_t **loots)
{
    loot_table_t **copy;
    int i = 0;

    for (; loots[i]; i++);
    copy = malloc(sizeof(loot_table_t *) * (i + 1));
    if (!copy)
        return (0);
    for (i = 0; loots[i]; i++)
        copy[i] = copy_loot(loots[i]);
    copy[i] = 0;
    return (copy);
}

entity_stat_t *copy_stat(entity_stat_t *stat)
{
    entity_stat_t *copy = malloc(sizeof(entity_stat_t));

    if (!copy)
        return (0);
    copy->armor = stat->armor;
    copy->health = stat->health;
    copy->rotationspeed = stat->rotationspeed;
    copy->speed = stat->speed;
    return (copy);
}

entity_t *copy_entity(entity_t *entity)
{
    entity_t *copy;

    if (!entity)
        return (0);
    copy = malloc(sizeof(entity_t));
    if (!copy)
        return (0);
    copy->body = copy_body(entity->body);
    copy->loot_table = copy_loottable(entity->loot_table);
    copy->stat = copy_stat(entity->stat);
    copy->id = entity->id;
    return (copy);
}
