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
#include "my.h"

void draw_defender_enemy(window_t *win, game_t *game)
{
    enemy_t *enemy = game->level->enemy_list;

    while (enemy != NULL) {
        draw_anim(enemy->animation, win->window);
        enemy = enemy->next;
    }
}

void draw_defender_game(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, game->view);
    draw_defender_background(win, game);
    draw_defender_enemy(win, game);
    play_shoot(&(game->level->shoot), win->window);
}

void draw_defender_minimap(window_t *win, game_t *game)
{
    sfRenderWindow_setView(win->window, win->minimap);
    draw_defender_minimap_background(win, game);
    draw_defender_minimap_enemy(win, game);
}

void draw_defender_hud(window_t *win, scene_t *menu, game_t *game)
{
    sfRenderWindow_setView(win->window, win->hud);
    draw_defender_sprite(win, menu);
    draw_defender_button(win, menu, game);
    draw_defender_text(win, menu);
}

void draw_defender(window_t *win, scene_t *menu, game_t *game)
{
    draw_defender_game(win, game);
    draw_defender_minimap(win, game);
    draw_defender_hud(win, menu, game);
    sfText_setString(menu->text[1].text,
        my_stoi(game->level->gold));
    sfText_setString(menu->text[3].text,
        my_stoi(game->level->wave));
    sfText_setString(menu->text[5].text,
        my_stoi(game->level->score));
    sfText_setString(menu->text[7].text,
        my_stoi(game->level->health));
}