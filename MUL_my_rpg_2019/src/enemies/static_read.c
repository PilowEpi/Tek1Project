/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch reading of Item and Enemy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "rpg.h"

int data_switch_body(dfile_t *data, int *i, e_bank_t *bank, int index[2])
{
    switch (data->data[*i]) {
        case 'B':
            *i += add_body_to_en(data, bank->enemies_bank[index[0] - 1], i, 0);
            break;
        case 'S':
            *i += add_body_to_item(data, bank->loot[index[1] - 1], i, 0);
            break;
    }
    return (0);
}

int data_switch_el(dfile_t *data, int *i, e_bank_t *bank, int index[2])
{
    switch(data->data[*i]) {
        case 'B':
        case 'S':
            data_switch_body(data, i, bank, index);
            break;
        case 'L':
            *i += add_loot(bank->enemies_bank[index[0] - 1], data, i);
            break;
        case 'O':
            *i += add_item(bank, &(index[1]), data, i);
            break;
        case 'E':
            *i += add_enemy_static(bank, &(index[0]), data, i);
            break;
        default:
            return (1);
    }
    return (0);
}

e_bank_t *init_bank(void)
{
    e_bank_t *bank = malloc(sizeof(e_bank_t));

    if (!bank)
        return (0);
    bank->enemies_bank = NULL;
    bank->loot = NULL;
    bank->npc_bank = NULL;
    return (bank);
}

e_bank_t *get_enemies(char *path)
{
    dfile_t *data = malloc(sizeof(dfile_t));
    char *data_t = read_file(path);
    e_bank_t *bank = init_bank();
    int data_size = get_filesize(path);
    int index[2] = {0, 0};
    int i = 0;

    if (!data || data_size == -1 || !data_t || !bank)
        return (0);
    data->data = data_t;
    data->data_size = data_size;
    while (i < data_size && i >= 0) {
        if (data_switch_el(data, &i, bank, index)) {
            return (0);
        }
        if (i < 0) {
            return (0);
        }
    }
    return (bank);
}
