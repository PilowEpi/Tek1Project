/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_defender
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"
#include "my.h"

void defender_portal_management(game_t *game)
{
    portal_t *portal = game->level->portal_list;
    sfVector2i pos;

    while (portal != NULL) {
        sfTime time = sfClock_getElapsedTime(portal->spawn);
        if (sfTime_asSeconds(time) >= portal->spawn_rate 
            && game->level->difficulty > 0) {
            pos = (sfVector2i) {portal->pos.x, portal->pos.y};
            add_enemy(pos, rand()%7, game->level, game);
            game->level->difficulty = game->level->difficulty - 1;
            sfClock_restart(portal->spawn);
        }
        portal = portal->next;
    }
}

sfVector2f get_newposition(sfVector2f from, sfVector2f to, float speed)
{
    float dx = to.x - from.x;
    float dy = to.y - from.y;
    float steps = (dx < 0 ? -dx : dx) > (dy < 0 ? -dy : dy) ?
        (dx < 0 ? -dx : dx) : (dy < 0 ? -dy : dy);
    float xinc = dx / steps;
    float yinc = dy / steps;

    if (steps == 0)
        return (from);
    if (steps < speed)
        return (to);
    for (int i = 0; i < speed; i++) {
        from.x += xinc;
        from.y += yinc;
    }
    return (from);
}

void is_alive(enemy_t *enemy, game_t *game)
{
    if (enemy->health > 0)
        return;
    remove_enemy(enemy, game->level);
    game->level->score = game->level->score + 10;
    game->level->gold = game->level->gold + 20 + rand()%20;
}

void enemy_attack(enemy_t *enemy, game_t *game, window_t *win)
{
    sfTime time = sfClock_getElapsedTime(enemy->attack_clock);
    float second = sfTime_asSeconds(time);

    if (second > 1) {
        sfClock_restart(enemy->attack_clock);
        game->level->health = game->level->health - rand()%10;
    }
    if (game->level->health <= 0) {
        win->type_scene = END_GAME;
    }
}

int start_defender(window_t *win, game_t *game)
{
    manage_event_defender(win, game);
    defender_portal_management(game);
    defender_tower_management(game);
    defender_enemy_management(win, game);
    draw_defender(win, &game->def_scene[IN_GAME], game);
    wave_handling(win, game);
    if (sfTime_asSeconds(
        sfClock_getElapsedTime(game->level->movement_clock))
        >= (1/60)*2)
        sfClock_restart(game->level->movement_clock);
    return (0);
}