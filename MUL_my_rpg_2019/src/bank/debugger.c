/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Bank Debugger
*/

#include <stdlib.h>

#include "rpg.h"
#include "my.h"

void show_bank_loots(loot_t **loots)
{
    for (int i = 0; loots && loots[i]; i++) {
        my_printf("Loot (%d):\n", i);
    }
}

void show_bank_information(e_bank_t *bank)
{
    if (!bank) {
        my_printf("Bank is NULL !\n");
        return;
    }
    my_printf("Bank :\n");
    show_bank_loots(bank->loot);
    show_entities(bank->npc_bank, bank->enemies_bank);
}