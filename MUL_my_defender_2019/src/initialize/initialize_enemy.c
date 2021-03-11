/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** initialize_enemy
*/

#include <stdlib.h>

#include "path_defender.h"
#include "defender.h"

void init_walking_sprite(sfTexture **walking_ss, int *returned)
{
    walking_ss[0] = sfTexture_createFromFile(enemy_marvin_walk, 0);
    walking_ss[1] = sfTexture_createFromFile(enemy_golem_walk, 0);
    walking_ss[2] = sfTexture_createFromFile(enemy_orc_walk, 0);
    walking_ss[3] = sfTexture_createFromFile(enemy_thief_walk, 0);
    walking_ss[4] = sfTexture_createFromFile(enemy_bat_walk, 0);
    walking_ss[5] = sfTexture_createFromFile(enemy_yeti_walk, 0);
    walking_ss[6] = sfTexture_createFromFile(enemy_trump_walk, 0);
    for (int i = 0; i < 7; i++)
        if (walking_ss[i] == NULL)
            *returned = 84;
}

void init_die_sprite(sfTexture **die_ss, int *returned)
{
    die_ss[0] = sfTexture_createFromFile(enemy_marvin_die, 0);
    die_ss[1] = sfTexture_createFromFile(enemy_golem_die, 0);
    die_ss[2] = sfTexture_createFromFile(enemy_orc_die, 0);
    die_ss[3] = sfTexture_createFromFile(enemy_thief_die, 0);
    die_ss[4] = sfTexture_createFromFile(enemy_bat_die, 0);
    die_ss[5] = sfTexture_createFromFile(enemy_yeti_die, 0);
    die_ss[6] = sfTexture_createFromFile(enemy_trump_die, 0);
    for (int i = 0; i < 7; i++)
        if (die_ss[i] == NULL)
            *returned = 84;
}

void init_attack_sprite(sfTexture **attack_ss, int *returned)
{
    attack_ss[0] = sfTexture_createFromFile(enemy_marvin_attack, 0);
    attack_ss[1] = sfTexture_createFromFile(enemy_golem_attack, 0);
    attack_ss[2] = sfTexture_createFromFile(enemy_orc_attack, 0);
    attack_ss[3] = sfTexture_createFromFile(enemy_thief_attack, 0);
    attack_ss[4] = sfTexture_createFromFile(enemy_bat_attack, 0);
    attack_ss[5] = sfTexture_createFromFile(enemy_yeti_attack, 0);
    attack_ss[6] = sfTexture_createFromFile(enemy_trump_attack, 0);
    for (int i = 0; i < 7; i++)
        if (attack_ss[i] == NULL)
            *returned = 84;
}

void init_enemies_texture(game_t *game, int *returned)
{
    game->texture = malloc(sizeof(game_texture_t));
    game->texture->walk_ss = malloc(sizeof(sfTexture *) * 7);
    game->texture->die_ss = malloc(sizeof(sfTexture *) * 7);
    game->texture->attack_ss = malloc(sizeof(sfTexture *) * 7);
    if (game->texture->walk_ss == NULL || game->texture->die_ss == NULL
        || game->texture->attack_ss == NULL) {
        *returned = 84;
        return;
    }
    init_walking_sprite(game->texture->walk_ss, returned);
    init_die_sprite(game->texture->die_ss, returned);
    init_attack_sprite(game->texture->attack_ss, returned);
}