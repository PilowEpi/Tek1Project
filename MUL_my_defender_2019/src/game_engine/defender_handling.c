/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defender_scene_draw
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

void defender_enemy_management(window_t *win, game_t *game)
{
    enemy_t *enemy = game->level->enemy_list;
    float dist = 0;
    sfVector2f from;
    sfVector2f to = (sfVector2f) {(15+rand()%3) * 101, (15+rand()%3) * 101};
    sfVector2f new_pos;
    sfTime time = sfClock_getElapsedTime(game->level->movement_clock);

    while (enemy != NULL) {
        dist = get_enemy_distance(enemy, (sfVector2f) {MAP_SIZE/2, MAP_SIZE/2});
        if (dist > 90 && sfTime_asSeconds(time) >= 1/60) {
            from = sfSprite_getPosition(enemy->animation->sprite);
            new_pos = get_newposition(from, to, (enemy->speed/(58+rand()%4)));
            enemy->pos = new_pos;
            sfSprite_setPosition(enemy->animation->sprite, new_pos);
        } else {
            enemy_attack(enemy, game, win);
        }
        is_alive(enemy, game);
        enemy = enemy->next;
    }
}

enemy_t *get_nearest_enemy(tower_t *tower, enemy_t *enemy)
{
    enemy_t *nearest = NULL;
    float dist;
    float min_dist = 200 + (50 * tower->level);

    while (enemy != NULL) {
        dist = get_enemy_distance(enemy,
            (sfVector2f) {tower->pos.x, tower->pos.y});
        if (dist < min_dist) {
            min_dist = dist;
            nearest = enemy;
            break;
        }
        enemy = enemy->next;
    }
    return (nearest);
}

void maybe_shoot_enemy(enemy_t *enemy, game_t *game, tower_t *tower)
{
    sfTime time = sfClock_getElapsedTime(tower->attack_clock);
    float second = sfTime_asSeconds(time);

    if (second >= tower->attack_rate) {
        shoot(tower, game,
            (sfVector2f) {tower->pos.x * 101, tower->pos.y * 101},
            enemy);
        sfClock_restart(tower->attack_clock);
    }
}

void defender_tower_management(game_t *game)
{
    tower_t *tower = game->level->tower_list;
    enemy_t *enemy = NULL;

    while (tower != NULL) {
        enemy = game->level->enemy_list;
        enemy = get_nearest_enemy(tower, enemy);
        if (enemy != NULL) {
            maybe_shoot_enemy(enemy, game, tower);
        }
        tower = tower->next;
    }
}

void wave_handling(window_t *win, game_t *game)
{
    sfVector2i pos;

    if (game->level->wave == 10 && game->level->enemy_list == NULL) {
        win->type_scene = END_GAME;
        return;
    }
    if (game->level->difficulty <= 0
        && game->level->enemy_list == NULL) {
        sfClock_restart(game->level->level_clock);
        game->level->wave = game->level->wave + 1;
        game->level->difficulty =
            (game->data.type + game->data.level_choose) * game->level->wave *3;
        for (int i = 0; i < game->level->wave; i++) {
            while (is_tile_portal((pos = get_random_pos()),
                game->level->portal_list));
            add_portal(pos, game->level, game);
        }
    }
}