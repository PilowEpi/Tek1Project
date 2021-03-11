/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** initialize_enemy
*/

#include <stdlib.h>

#include "path_defender.h"
#include "defender.h"
#include "dico_defender.h"

void init_die_animation(game_t *game, int *returned)
{
    for (int i = 0; i <= TRUMP; i++) {
        game->texture->die_ssa[i] = create_animation(
            game->texture->die_sss[i],
            enemy_ss_die[i].duration,
            sfFalse
        );
        if (game->texture->die_ssa[i] == NULL) {
            *returned = 84;
            return;
        }
    }
}

void init_attack_animation(game_t *game, int *returned)
{
    for (int i = 0; i <= TRUMP; i++) {
        game->texture->attack_ssa[i] = create_animation(
            game->texture->attack_sss[i],
            enemy_ss_attack[i].duration,
            sfFalse
        );
        if (game->texture->attack_ssa[i] == NULL) {
            *returned = 84;
            return;
        }
    }
}

void init_walk_animation(game_t *game, int *returned)
{
    for (int i = 0; i <= TRUMP; i++) {
        game->texture->walk_ssa[i] = create_animation(
            game->texture->walk_sss[i],
            enemy_ss_walk[i].duration,
            sfTrue
        );
        if (game->texture->walk_ssa[i] == NULL) {
            *returned = 84;
            return;
        }
    }
}

void init_spritesheet(game_t *game)
{
    for (int i = 0; i <= TRUMP; i++) {
        game->texture->walk_sss[i] = malloc(sizeof(spritesheet_t));
        game->texture->walk_sss[i]->texture = game->texture->walk_ss[i];
        game->texture->walk_sss[i]->width = enemy_ss_walk[i].width;
        game->texture->walk_sss[i]->margin = enemy_ss_walk[i].margin;
        game->texture->walk_sss[i]->sprite_count = enemy_ss_walk[i].
            sprite_count;
        game->texture->die_sss[i] = malloc(sizeof(spritesheet_t));
        game->texture->die_sss[i]->texture = game->texture->die_ss[i];
        game->texture->die_sss[i]->width = enemy_ss_die[i].width;
        game->texture->die_sss[i]->margin = enemy_ss_die[i].margin;
        game->texture->die_sss[i]->sprite_count = enemy_ss_die[i].
            sprite_count;
        game->texture->attack_sss[i] = malloc(sizeof(spritesheet_t));
        game->texture->attack_sss[i]->texture = game->texture->attack_ss[i];
        game->texture->attack_sss[i]->width = enemy_ss_attack[i].width;
        game->texture->attack_sss[i]->margin = enemy_ss_attack[i].margin;
        game->texture->attack_sss[i]->sprite_count = enemy_ss_attack[i].
            sprite_count;
    }
}

void init_enemies_spritesheet(game_t *game, int *returned)
{
    game->texture->walk_sss = malloc(sizeof(spritesheet_t *) * 7);
    game->texture->die_sss = malloc(sizeof(spritesheet_t *) * 7);
    game->texture->attack_sss = malloc(sizeof(spritesheet_t *) * 7);
    game->texture->walk_ssa = malloc(sizeof(spritesheet_t *) * 7);
    game->texture->die_ssa = malloc(sizeof(spritesheet_t *) * 7);
    game->texture->attack_ssa = malloc(sizeof(spritesheet_t *) * 7);
    if (game->texture->walk_sss == NULL || game->texture->attack_sss == NULL ||
        game->texture->die_sss == NULL) {
        *returned = 84;
        return;
    }
    if (game->texture->walk_ssa == NULL || game->texture->attack_ssa == NULL ||
        game->texture->die_ssa == NULL) {
        *returned = 84;
        return;
    }
    init_spritesheet(game);
    init_walk_animation(game, returned);
    init_die_animation(game, returned);
    init_attack_animation(game, returned);
}
