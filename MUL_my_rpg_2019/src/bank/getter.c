/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch reading enemy
*/

#include <stdlib.h>

#include "rpg.h"

int get_enemies_bank_size(e_bank_t *bank)
{
    entity_t **enemies = bank->enemies_bank;
    int size = 0;

    for (; enemies && enemies[size]; size++);
    return (size);
}

int get_loot_bank_size(e_bank_t *bank)
{
    loot_t **loot = bank->loot;
    int size = 0;

    for (; loot && loot[size]; size++);
    return (size);
}