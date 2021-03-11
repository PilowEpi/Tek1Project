/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** tower_management
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "my.h"
#include "dico_defender.h"

int sell(void *data, void *win, void *gam)
{
    game_t *game = (game_t *)gam;

    remove_tower(game->level->tile_s, game->level);
    game->level->gold = game->level->gold + 50 + rand()%26;
    game->level->hud = EMPTY_CELL;
}

int levelup(void *data, void *win, void *gam)
{
    game_t *game = (game_t *)gam;
    tower_t *tower = get_tower(game->level->tile_s, game->level->tower_list);
    sfIntRect text;

    if (tower == NULL  || tower->level == 3 || game->level->gold < 100)
        return;
    game->level->gold = game->level->gold - 100;
    tower->level = tower->level + 1;
    tower->attack_rate = tower->attack_rate - 0.1;
    text = sfSprite_getTextureRect(tower->sprite);
    text.left = (tower_ss_info[tower->type].width +
                tower_ss_info[tower->type].margin) * (tower->level - 1);
    text.width = tower_ss_info[tower->type].width;
    sfSprite_setTextureRect(tower->sprite, text);
}

int place_tower(void *data, void *win, void *gam)
{
    int tower_type = (*(int *)data) - 2;
    game_t *game = (game_t *)gam;

    if (game->level->gold < 100)
        return (0);
    game->level->gold = game->level->gold - 100;
    add_tower(game->level->tile_s, tower_type, game->level, game);
    game->level->hud = TOWER_CELL;
    return (1);
}