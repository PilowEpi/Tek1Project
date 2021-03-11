/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Draw loop
*/

#include <stdlib.h>
#include <stdio.h>

#include "rpg.h"

void add_item_to_word(globals_t *gl, int id, sfVector2f pos)
{
    int lc = 0;
    loot_t **new;
    loot_t **old = gl->rooms[gl->room_index]->items;

    for (; old && old[lc]; lc++);
    new = malloc(sizeof(loot_t *) * (lc + 2));
    if (!new)
        return;
    for (int i = 0; i < lc; i++)
        new[i] = old[i];
    new[lc] = copy_item(gl, id);
    new[lc + 1] = 0;
    if (!new[lc])
        return;
    set_item_pos(new[lc], pos);
    if (gl->rooms[gl->room_index]->items)
        free(gl->rooms[gl->room_index]->items);
    gl->rooms[gl->room_index]->items = new;
    return;
}

void drop_item(globals_t *gl, loot_table_t *loot, sfVector2f pos)
{
    int prob = rand()%100;

    for (int i = 0; i < loot->quantity; i++) {
        prob = rand()%100;
        if (prob >= loot->prob)
            continue;
        pos = (sfVector2f) {pos.x + (rand()%200) - 100,
            pos.y + (rand()%200) - 100};
        add_item_to_word(gl, loot->id, pos);
    }
}

void drop_enemy_loots(globals_t *gl, entity_t *entity)
{
    sfVector2f pos = entity->pos;

    if (!entity)
        return;
    for (int i = 0; entity->loot_table &&
        entity->loot_table[i]; i++) {
        drop_item(gl, entity->loot_table[i], pos);
    }
}

void check_enemies_life(globals_t *gl)
{
    entity_t **enemies = gl->rooms[gl->room_index]->enemies;

    for (int i = 0; enemies && enemies[i] != NULL; i++) {
        if (enemies[i]->stat->health <= 0) {
            drop_enemy_loots(gl, enemies[i]);
            update_xp(gl->hud, rand()%30+20);
            remove_enemy(gl, enemies[i]);
            i = -1;
            enemies = gl->rooms[gl->room_index]->enemies;
        }
    }
}

void player_melee_weapon(entity_t *entity, weapon_t *weapon, globals_t *gl)
{
    sfColor attack_color = sfColor_fromRGB(rand()%255, rand()%255, rand()%255);
    entity_t **enemies = gl->rooms[gl->room_index]->enemies;

    for (int i = 0; enemies && enemies[i]; i++) {
        if (!(get_distance(enemies[i]->pos, entity->pos) <= weapon->range))
            continue;
        play_melee_attack(gl, gl->player->pos, sfBlue);
        enemies[i]->stat->health = enemies[i]->stat->health - weapon->damage;
    }
    check_enemies_life(gl);
}
