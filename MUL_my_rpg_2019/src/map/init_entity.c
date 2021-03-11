/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch map read entities
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "rpg.h"
#include "my.h"

int add_weapon_to_entity(entity_t *entity, weapon_t *weapon)
{
    int lc = 0;
    weapon_t **weapons;

    for (; entity->weapon_list && entity->weapon_list[lc]; lc++);
    weapons = malloc(sizeof(entity_t *) * (lc + 2));
    if (!weapons)
        return (1);
    for (int i = 0; i < lc; i++)
        weapons[i] = entity->weapon_list[i];
    weapons[lc] = weapon;
    weapons[lc + 1] = 0;
    if (!weapons[lc])
        return (1);
    if (entity->weapon_list)
        free(entity->weapon_list);
    entity->weapon_list = weapons;
    return (0);
}

int init_distance_weapon(entity_t *entity)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (!weapon)
        return (1);
    weapon->type = 0;
    weapon->damage = 10 + rand()%20;
    weapon->range = 300 + rand()%200;
    weapon->cooldown = (float) rand()/(float)(RAND_MAX/1);
    weapon->clock = sfClock_create();
    return (add_weapon_to_entity(entity, weapon));
}

int init_close_weapon(entity_t *entity)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    if (!weapon)
        return (1);
    weapon->type = 1;
    weapon->damage = 20 + rand()%10;
    weapon->range = 50 + rand()%10;
    weapon->cooldown = (float) rand()/(float)(RAND_MAX/5);
    weapon->clock = sfClock_create();
    return (add_weapon_to_entity(entity, weapon));
}

entity_t *init_new_enemy(dfile_t *data, sfVector2f pos, char info[3])
{
    entity_t *enemy = NULL;
    int bank_size = get_enemies_bank_size(data->gl->bank);

    if (info[2] > bank_size)
        return (NULL);
    enemy = copy_entity(data->gl->bank->enemies_bank[info[1]]);
    if (!enemy)
        return (0);
    enemy->pos = pos;
    enemy->state = (int) info[2];
    enemy->weapon_list = NULL;
    if (info[1] % 2 == 0) {
        init_distance_weapon(enemy);
    } else {
        init_close_weapon(enemy);
    }
    return (enemy);
}

entity_t *init_new_npc(dfile_t *data, sfVector2f pos, char info[3])
{

}
