/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** defender.h
*/

#ifndef DEFENDER_H
#define DEFENDER_H

#include "struct_defender.h"

// Launch game

int launch_init(void);
int play_game(window_t *win, game_t *game);

// [Draw Funct]

int draw_game(window_t *win, game_t *game);

// Starting Scene Funct

int start_menu(window_t *win, game_t *game);
int start_option(window_t *win, game_t *game);
int start_levels(window_t *win, game_t *game);
int start_defender(window_t *win, game_t *game);
int start_pause(window_t *win, game_t *game);
int start_end(window_t *win, game_t *game);

// [Event Funct]

int manage_event_menu(window_t *win, game_t *game);
int manage_event_option(window_t *win, game_t *game);
int manage_event_levels(window_t *win, game_t *game);
int manage_event_pause(window_t *win, game_t *game);
int manage_event_end(window_t *win, game_t *game);
int manage_event_defender(window_t *win, game_t *game);

// [defend tower Funct]
void defender_tower_management(game_t *);
void wave_handling(window_t *, game_t *);
// generic init sprite

int init_sprite(sprite_t *sprite, const init_sprite_t *sprite_data);
int init_button(button_t *button, const init_but_t *but_data);
int init_text(text_t *text, const init_text_t *text_data);

int init_sprite_texture(sprite_t *sprite, char *pathname);
int create_sprite(sprite_t *sprite);
void init_vector(sprite_t *sprite, float x, float y);
void init_init_vector(sprite_t *sprite, float x, float y);

// main init

void initialize_window(window_t *win, int *returned);
void initialize_scene(scene_t *scene, int *returned,
const init_scene data_scene);
void initialize_level(void *, void *, void *);
void init_enemies_texture(game_t *, int *);
void init_enemies_spritesheet(game_t *, int *);
int is_tile_portal(sfVector2i, portal_t *);
void initialize_defender(game_t *game, int *returned);
sfVector2f get_newposition(sfVector2f from, sfVector2f to, float speed);
sfVector2i get_random_pos(void);


// [Button Function]

int close_window(void *data, void *win, void *game);
int swap_to_menu(void *data, void *win, void *game);
int swap_to_in_game(void *data, void *win, void *game);
int swap_to_option(void *data, void *win, void *game);
int swap_to_end_game(void *data, void *win, void *game);
int swap_to_levels(void *data, void *win, void *game);
int swap_small_size(void *data, void *win, void *game);
int swap_big_size(void *data, void *win, void *game);
int touch_add(void *data, void *win, void *game);
int touch_sub(void *data, void *win, void *game);
int place_tower(void *data, void *win, void *game);
int levelup(void *data, void *win, void *game);
int sell(void *data, void *win, void *game);

// [DESTROY]

int destroy_level(window_t *window, game_t *game);
int destroy_defender(window_t *win, game_t *game);

// [TOWER Function]

tower_t *get_tower(sfVector2i pos, tower_t *head);
int sell(void *data, void *win, void *gam);
int levelup(void *data, void *win, void *gam);
int place_tower(void *data, void *win, void *gam);

// [PORTAL Function]
portal_t *get_portal(sfVector2i pos, portal_t *head);

// Enemy
float get_enemy_distance(enemy_t *enemy, sfVector2f pos);

// animation
/* Animation handling */
animation_t *create_animation(spritesheet_t *, float, sfBool);
animation_t *copy_animation(animation_t *);
void next_anim(animation_t *);
void draw_anim(animation_t *, sfRenderWindow *);
void destroy_animation(animation_t *);

/* Spritesheet handling */
spritesheet_t *load_spritesheet(char *, int, int, int);
void destroy_spritesheet(spritesheet_t *);

int is_tile_tower(sfVector2i pos, tower_t *head);
void remove_tower(sfVector2i pos, level_t *level);
void add_tower(sfVector2i pos, enum tower_type tower_type,
level_t *level, game_t *game);
void destroy_tower(tower_t *tower);
void upgrade_tower(sfVector2i pos, tower_t *head);
tower_t *init_tower(enum tower_type tower_type, game_t *game);

portal_t *init_portal(sfVector2i pos, game_t *game);
void add_portal(sfVector2i pos, level_t *level, game_t *game);
void destroy_portal(portal_t *portal);
void remove_portal(sfVector2i pos, level_t *level);

float get_enemy_distance(enemy_t *enemy, sfVector2f pos);
enemy_t *init_enemy(sfVector2i pos, enum enemy_type enemy_type, game_t *game);
void add_enemy(sfVector2i pos, enum enemy_type enemy_type,
level_t *level, game_t *game);
void destroy_enemy(enemy_t *tower);
void remove_enemy(enemy_t *enemy, level_t *level);

void draw_defender_text(window_t *win, scene_t *option);
void draw_defender_text(window_t *win, scene_t *option);
void draw_defender_button(window_t *win, scene_t *menu, game_t *game);
void defender_mainback(window_t *win, game_t *game, int i, int y);
void draw_defender_background(window_t *win, game_t *game);
void set_mptile_color(sfSprite *back, sfVector2i selected,
sfVector2i current, game_t *game);
void draw_defender_minimap_background(window_t *win, game_t *game);
void draw_defender_minimap_enemy(window_t *win, game_t *game);
void draw_defender_enemy(window_t *win, game_t *game);
void draw_defender_game(window_t *win, game_t *game);
void draw_defender_minimap(window_t *win, game_t *game);
void draw_defender_sprite(window_t *, scene_t *);
void draw_defender_hud(window_t *win, scene_t *menu, game_t *game);
void draw_defender(window_t *win, scene_t *menu, game_t *game);
void defender_portal_management(game_t *game);
sfVector2f get_newposition(sfVector2f from, sfVector2f to, float speed);
void is_alive(enemy_t *enemy, game_t *game);
void enemy_attack(enemy_t *enemy, game_t *game, window_t *win);
void defender_enemy_management(window_t *win, game_t *game);
enemy_t *get_nearest_enemy(tower_t *tower, enemy_t *enemy);
void play_shoot(shoot_t **, sfRenderWindow *);

#endif
