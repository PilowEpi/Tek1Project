/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defender_scene_draw
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

void defender_mainback(window_t *win, game_t *game, int i, int y)
{
    sfSprite *back = game->level->background;
    sfVector2i selected = game->level->tile_s;
    sfVector2i current = (sfVector2i) {i, y};
    sfVector2f pos = (sfVector2f) {i * 101, y * 101};
    tower_t *tower = NULL;
    portal_t *portal = NULL;

    sfSprite_setPosition(back, pos);
    if (i == selected.x && y == selected.y)
        sfSprite_setColor(back, sfGreen);
    sfRenderWindow_drawSprite(win->window, back, 0);
    if (i == selected.x && y == selected.y)
        sfSprite_setColor(back, sfWhite);
    if ((tower = get_tower(current, game->level->tower_list)) != NULL)
        sfRenderWindow_drawSprite(win->window, tower->sprite, 0);
    else if ((portal = get_portal(current, game->level->portal_list)) != NULL)
        sfRenderWindow_drawSprite(win->window, portal->sprite, 0);
    if (i == MAP_SIZE/2 && y == MAP_SIZE/2)
        sfRenderWindow_drawSprite(win->window, game->level->castle, 0);
}

void draw_defender_background(window_t *win, game_t *game)
{
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            defender_mainback(win, game, i, y);
        }
    }
}

void set_mptile_color(sfSprite *back, sfVector2i selected,
sfVector2i current, game_t *game)
{
    sfColor back_col = sfColor_fromRGBA(0, 0, 0, 170);
    sfColor back_sel = sfColor_fromRGBA(255, 0, 0, 200);
    sfColor tower_color = sfColor_fromRGBA(0, 255, 0, 200);
    sfColor portal_color = sfColor_fromRGBA(247, 202, 24, 1);

    if (current.x == selected.x && current.y == selected.y)
        sfSprite_setColor(back, back_sel);
    else if (current.x == MAP_SIZE/2 && current.y == MAP_SIZE/2)
        sfSprite_setColor(back, sfBlue);
    else if (is_tile_tower(current, game->level->tower_list))
        sfSprite_setColor(back, tower_color);
    else if (is_tile_portal(current, game->level->portal_list))
        sfSprite_setColor(back, portal_color);
    else
        sfSprite_setColor(back, back_col);
}

void draw_defender_minimap_background(window_t *win, game_t *game)
{
    sfSprite *back = game->level->background;
    sfVector2i selected = game->level->tile_s;
    sfVector2f pos = (sfVector2f) {0, 0};

    for (int i = 0; i < MAP_SIZE; i++) {
        for (int y = 0; y < MAP_SIZE; y++) {
            set_mptile_color(back, selected, (sfVector2i) {i, y}, game);
            pos.x = i * 100;
            pos.y = y * 100;
            sfSprite_setPosition(back, pos);
            sfRenderWindow_drawSprite(win->window, back, 0);
            sfSprite_setColor(back, sfWhite);
        }
    }
}

void draw_defender_minimap_enemy(window_t *win, game_t *game)
{
    enemy_t *enemy = game->level->enemy_list;
    sfCircleShape *shape = sfCircleShape_create();

    if (shape == NULL)
        return;
    sfCircleShape_setFillColor(shape, sfYellow);
    sfCircleShape_setPointCount(shape, 100);
    sfCircleShape_setRadius(shape, 25);
    while (enemy != NULL) {
        sfCircleShape_setPosition(shape, enemy->pos);
        sfRenderWindow_drawCircleShape(win->window, shape, 0);
        enemy = enemy->next;
    }
}