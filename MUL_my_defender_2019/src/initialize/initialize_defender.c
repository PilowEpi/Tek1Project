/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** initialize_defender
*/

#include <stdlib.h>
#include "path_defender.h"
#include "defender.h"
#include "dico_defender.h"

void init_tower_texture(game_t *game, int *returned)
{
    game->texture->towers = malloc(sizeof(sfTexture *) * 4);
    game->texture->towers[0] = sfTexture_createFromFile(tower_1, 0);
    game->texture->towers[1] = sfTexture_createFromFile(tower_2, 0);
    game->texture->towers[2] = sfTexture_createFromFile(tower_3, 0);
    game->texture->towers[3] = sfTexture_createFromFile(tower_4, 0);
    for (int i = 0; i < 4; i++)
        if (game->texture->towers[i] == NULL)
            *returned = 84;
}

void init_background_texture(game_t *game, int *returned)
{
    game->texture->backgrounds = malloc(sizeof(sfTexture *) * 4);
    game->texture->castles = malloc(sizeof(sfTexture *) * 4);
    if (game->texture->backgrounds == NULL)
        *returned = 84;
    game->texture->backgrounds[0] = sfTexture_createFromFile(forest_tile, 0);
    game->texture->backgrounds[1] = sfTexture_createFromFile(desert_tile, 0);
    game->texture->backgrounds[2] = sfTexture_createFromFile(ice_tile, 0);
    game->texture->backgrounds[3] = sfTexture_createFromFile(volcano_tile, 0);
    game->texture->castles[0] = sfTexture_createFromFile(default_castle, 0);
    game->texture->castles[1] = game->texture->castles[0];
    game->texture->castles[2] = sfTexture_createFromFile(winter_castle, 0);
    game->texture->castles[3] = game->texture->castles[0];
    for (int i = 0; i < 4; i++)
        sfTexture_setRepeated(game->texture->backgrounds[i], sfTrue);
    for (int i = 0; i < 4; i++)
        if (game->texture->backgrounds[i] == NULL)
            *returned = 84;
}

void init_projectile_texture(game_t *game, int *returned)
{
    game->texture->projectile = malloc(sizeof(sfTexture *) * 4);
    if (game->texture->projectile == NULL) {
        *returned = 84;
        return;
    }
    game->texture->projectile[ARCHER] = sfTexture_createFromFile(archer_p, 0);
    game->texture->projectile[BOMB] = sfTexture_createFromFile(bomb_p, 0);
    game->texture->projectile[MAGIC] = sfTexture_createFromFile(magic_p, 0);
    game->texture->projectile[SLOW] = sfTexture_createFromFile(slow_p, 0);

}

void initialize_defender(game_t *game, int *returned)
{
    if (*returned == 84)
        return;
    game->data.type = FOREST;
    init_enemies_texture(game, returned);
    init_tower_texture(game, returned);
    init_background_texture(game, returned);
    init_enemies_spritesheet(game, returned);
    init_projectile_texture(game, returned);
    game->texture->portal = sfTexture_createFromFile(portal_a, 0);
}

void init_level_sprite(game_t *game)
{
    sfVector2f pos = (sfVector2f) {(MAP_SIZE/2)*101, (MAP_SIZE/2)*101 - 50};
    level_t *level = game->level;

    level->background = sfSprite_create();
    level->castle = sfSprite_create();
    sfSprite_setTexture(level->background,
        game->texture->backgrounds[level->type], 0);
    sfSprite_setTexture(level->castle, game->texture->castles[level->type], 0);
    sfSprite_setPosition(level->castle, pos);
}

void init_level_views(window_t *win, game_t *game)
{
    game->view = sfView_createFromRect(
        (sfFloatRect)
        {0, 0, 1920 * win->scale_ratio, 1080 * win->scale_ratio});
    win->minimap = sfView_createFromRect(
        (sfFloatRect)
        {0, 0, 100*(MAP_SIZE), 100*(MAP_SIZE)});
    sfView_setViewport(win->minimap,
        (sfFloatRect) {0.85f, 0.f, 0.15f, 0.15f * 16/9});
    win->hud = sfView_createFromRect(
        (sfFloatRect)
        {0, 0, 1920 * win->scale_ratio, 1080 * win->scale_ratio});
}

void init_level(level_t *level, game_t *game, float difficulty)
{
    level->type = game->data.type;
    level->wave = 0;
    level->difficulty = difficulty;
    level->level_clock = sfClock_create();
    level->movement_clock = sfClock_create();
    level->tile_s = (sfVector2i) {65, 65};
    level->tower_list = NULL;
    level->enemy_list = NULL;
    level->portal_list = NULL;
    level->hud = CASTLE_CELL;
    level->shoot = NULL;
    level->score = 0;
    level->gold = 500 * (level->type + 1);
    level->health = 500 * (level->type + 1);
}

sfVector2i get_random_pos(void)
{
    int side = 0;
    sfVector2i pos;

    side = rand()%2;
    if (!side) {
        side = rand()%2;
        pos.x = side == 0 ? rand()%5 : rand()%5 + MAP_SIZE - 5;
        pos.y = rand()%MAP_SIZE;
    } else {
        side = rand()%2;
        pos.x = rand()%MAP_SIZE;
        pos.y = side == 0 ? rand()%5 : rand()%5 + MAP_SIZE - 5;
    }
    return (pos);
}

void init_portals(level_t *level, game_t *game)
{
    int portal = game->data.level_choose + level->type;
    sfVector2i pos;

    for (int i = 0; i < portal; i++) {
        while (is_tile_portal((pos = get_random_pos()), level->portal_list));
        add_portal(pos, level, game);
    }
}

void initialize_level(void *data, void *wi, void *gam)
{
    int level_choose = *((int *)data);
    game_t *game = (game_t *)gam;
    window_t *win = (window_t *) wi;
    float difficulty = (game->data.type + level_choose) * 3;
    level_t *level = malloc(sizeof(level_t));

    if (level == NULL)
        return;
    init_level(level, game, difficulty);
    game->data.level_choose = level_choose;
    game->level = level;
    init_level_views(win, game);
    init_level_sprite(game);
    init_portals(level, game);
}