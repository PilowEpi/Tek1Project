/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Draw loop
*/

#include <stdlib.h>
#include <stdio.h>

#include "rpg.h"

void use_distance_weapon(entity_t *entity,
    weapon_t *weapon, sfVector2f direction, globals_t *gl)
{
    sfTime time = sfClock_getElapsedTime(weapon->clock);
    float seconds = sfTime_asSeconds(time);
    sfVector2f dir = (sfVector2f) {direction.x, direction.y};

    if (weapon->cooldown >= seconds) {
        return;
    }
    if (entity == gl->player) {
        add_bullet(gl, dir, entity, weapon->damage);
    } else {
        dir = gl->player->pos;
        add_bullet(gl, dir, entity, weapon->damage);
    }
    sfClock_restart(weapon->clock);
}

void remove_enemy(globals_t *gl, entity_t *entity)
{
    entity_t **enemies = gl->rooms[gl->room_index]->enemies;
    entity_t **new;
    int ec = 0;
    int index = 0;

    for (; enemies && enemies[ec]; ec++);
    new = malloc(sizeof(entity_t *) * ec);
    for (int i = 0; i < ec; i++)
        if (enemies[i] != entity)
            new[index++] = enemies[i];
    new[index] = 0;
    free(gl->rooms[gl->room_index]->enemies);
    gl->rooms[gl->room_index]->enemies = new;
}

loot_t *copy_item(globals_t *gl, int id)
{
    int bank_size = get_loot_bank_size(gl->bank);
    loot_t *loot;
    loot_t **gna = gl->bank->loot;

    if (id > bank_size)
        return (0);
    loot = malloc(sizeof(loot_t));
    loot->id = id;
    loot->body = copy_body(gna[id]->body);
    return (loot);
}

void set_item_pos(loot_t *loot, sfVector2f pos)
{
    for (int i = 0; loot->body && loot->body[i]; i++) {
        sfConvexShape_setPosition(loot->body[i], pos);
    }
}

void remove_item_from_word(globals_t *gl, loot_t *loot)
{
    int lc = 0;
    int index = 0;
    loot_t **new;
    loot_t **old = gl->rooms[gl->room_index]->items;

    for (; old && old[lc]; lc++);
    new = malloc(sizeof(loot_t *) * (lc));
    if (!new)
        return;
    for (int i = 0; i < lc; i++)
        if (old[i] != loot)
            new[index++] = old[i];
    new[index] = 0;
    if (gl->rooms[gl->room_index]->items)
        free(gl->rooms[gl->room_index]->items);
    gl->rooms[gl->room_index]->items = new;
}
