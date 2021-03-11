/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** main header
*/

#ifndef _RPG_H
#define _RPG_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>

#include "engine.h"
#include "hud.h"
#include "particle.h"

typedef struct bullet {
    sfVector2f direction;
    sfVector2f pos;
    int damage;
    entity_t *shooter;
} bullet_t;

typedef struct effects {
    sfShader *ennemy_sh;
    sfShader *fog_sh;
    sfRenderStates *ennemy_rs;
    sfRenderStates *fog_rs;
    sfTexture *main_fog;
    sfSprite *fog;
} effects_t;

typedef struct gl {
    sfVideoMode mode;
    sfShader *shader;
    sfRenderStates *state;
    sfClock *clock;
    room_t **rooms;
    sfConvexShape ***light_polys;
    entity_t *player;
    sfView *main_view;
    sfView *hud_view;
    e_bank_t *bank;
    sfGlslVec3  *light_shader_obj;
    sfText *end_room;
    sfText *quest;
    int room_index;
    hud_t *hud;
    part_t *particle;
    effects_t *effects;
    void *data;
    bullet_t **bullet;
} globals_t;

typedef struct file {
    unsigned char *data;
    int data_size;
    globals_t *gl;
} dfile_t;

void handle_main_event(sfRenderWindow *window, sfEvent *event, globals_t *gl);
void init_main(globals_t *gl);
void game_loop(sfRenderWindow *window, globals_t *gl);

void init_effects(globals_t *gl);

// init Hud
void init_hud(globals_t *gl);
void set_points(sfConvexShape *shape, sfFloatRect rect);
void update_ends(globals_t *gl);
void consume_item(globals_t *gl, sfEvent *event);

// light
int alloc_poly_light(sfConvexShape ***poly, room_t *room, light_t *light);
sfConvexShape ***alloc_polygones(room_t *room);
void free_polygones(sfConvexShape ***poly);

sfVector2f get_inter(sfVector2f from, sfVector2f to, sfVector2f f_p,
    sfVector2f t_p);

sfVector2f *get_raycasts(light_t *light, room_t *room, int, int);
int get_point_counts(room_t *room);
void update_lights(sfConvexShape ***poly, globals_t *gl);

void do_raycast(sfVector2f *buf, sfVector2f from, sfVector2f to, room_t *room);
void clean_rays(sfVector2f *casts, light_t *light, room_t *room);

//Player init
int init_player(globals_t *room);

//Player movement function
void mouse_move_event(sfEvent *, entity_t *, globals_t *, sfRenderWindow *);
int move_entity(entity_t *entity, sfVector2f to, int speed, globals_t *gl);
int move_player_event(sfRenderWindow *window, sfEvent *event, globals_t *gl);
void move_camera(globals_t *gl);

// Room init
int add_wall(dfile_t *a_data, room_t *room, int *i);
int add_room(room_t ***rooms, int *size, dfile_t *data, int *i);
int add_light(dfile_t *a_data, room_t *room, int *i);
room_t **get_rooms(char *path, globals_t *gl);
e_bank_t *get_enemies(char *path);

// Entity copy init
entity_t *init_new_enemy(dfile_t *data, sfVector2f pos, char info[3]);
entity_t *init_new_npc(dfile_t *data, sfVector2f pos, char info[3]);

// Handling
int add_info(dfile_t *a_data, room_t *room, int *i);
int add_entity(dfile_t *a_data, room_t *room, int *i);
int add_body_to_en(dfile_t *a_data, entity_t *entity, int *i, int j);
int add_loot(entity_t *entity, dfile_t *data, int *i);
int add_item(e_bank_t *bank, int *item_size, dfile_t *data, int *i);
int add_body_to_item(dfile_t *a_data, loot_t *item, int *i, int j);
int add_enemy_static(e_bank_t *bank, int *size, dfile_t *data, int *i);
void check_enemies_life(globals_t *gl);
int move_enemy(entity_t *entity, globals_t *gl);
int attack_event(sfRenderWindow *window, globals_t *gl, sfEvent *event);
void use_weapon(entity_t *entity,
    weapon_t *weapon, sfVector2f direction, globals_t *gl);

// Light handling
int check_bound(sfVector2f *buf, sfVector2f from, sfVector2f to,
    sfFloatRect rect);
int check_raycast(sfVector2f *buf, sfFloatRect rect, int *written,
    sfConvexShape *shape);

// Debugger functions
void show_rooms_information(room_t **rooms);
void show_bank_information(e_bank_t *bank);
void show_bank_loots(loot_t **loots);
void show_entities(entity_t **npc, entity_t **e);

// Gameplay function
int is_on_end(globals_t *gl);
void swap_room_event(sfEvent *event, globals_t *gl);
void show_swap_room_key(sfRenderWindow *window, globals_t *gl);

void add_item_to_word(globals_t *gl, int id, sfVector2f pos);
void remove_item_from_word(globals_t *gl, loot_t *loot);
loot_t *copy_item(globals_t *gl, int id);

#include "lib_csfml.h"
#include "rpg_struct.h"

// INIT GAME

int init_globals(glo_t *gl);
int init_game(glo_t *gl);

// LAUNCH_GAME

int play_game(glo_t *gl);

// DRAW FUNCTIONS

int draw_scene(glo_t *gl);
void draw_scene_sprite(window_t *win, scene_t *scene);
void draw_scene_button(window_t *win, scene_t *scene);
void draw_scene_text(window_t *win, scene_t *scene);

int draw_menu(glo_t *gl);
int draw_option(glo_t *gl);
int draw_pause(glo_t *gl);
int draw_end(glo_t *gl);
int draw_skill(glo_t *gl);
int draw_game(glo_t *gl);
int draw_tuto(glo_t *gl);

// EVENT FUNCTIONS

int handle_event(sfRenderWindow *win, sfEvent *event, glo_t *gl);
void button_evt_poll(window_t *win, glo_t *game, int scene);

int menu_event(glo_t *gl);
int option_event(glo_t *gl);
int pause_event(glo_t *gl);
int end_event(glo_t *gl);
int skill_event(glo_t *gl);
int main_event(glo_t *gl);
int tuto_event(glo_t *gl);

// BUTTON FUNCTIONS

int close_window(void *data);

int swap_to_menu(void *data);
int swap_to_option(void *data);
int swap_to_pause(void *data);
int swap_to_play(void *data);
int swap_to_end(void *data);
int swap_to_skill(void *data);
int swap_to_tuto(void *data);

int make_win(void *data);
int make_lose(void *data);

int turn_on_sound(void *data);
int mute_sound(void *data);

// LOUIS ICI !!!!!!!!

// Here data is globals_t *gl


int more_armor(void *data);
int more_speed(void *data);
int more_dmg(void *data);
int more_healh(void *data);
int more_ligth(void *data);
int get_pistol(void *data);


// DESTROY_GAME

int clean_memory(glo_t *gl);
void destroy_win(window_t *win);
int init_player_body(sfConvexShape *shape, sfVector2f pos);
int init_player(globals_t *room);
void init_text_end_room(globals_t *gl);
void init_engine(globals_t *gl);
void init_lights_at_room(globals_t *gl, int index);
sfConvexShape **init_inventory(sfVideoMode mode);
void init_armor(hud_t *hud, globals_t *gl);
void init_life(hud_t *hud, globals_t *gl);
void update_xp(hud_t *hud, float xp);
void draw_hud(sfRenderWindow *window, globals_t *gl);
void draw_inv(sfRenderWindow *window, globals_t *gl);
void update_light_position(sfRenderWindow *window, globals_t *gl);
void draw_lights(sfRenderWindow *window, globals_t *gl);
void draw_walls(sfRenderWindow *window, globals_t *gl);
void draw_enemies(sfRenderWindow *window, globals_t *gl);
void update_enemies_pos(globals_t *gl);
void draw_items(sfRenderWindow *window, globals_t *gl);
void draw_mainview(sfRenderWindow *window, globals_t *gl);
void draw_hudview(sfRenderWindow *window, globals_t *gl, double time);
void add_item_to_word(globals_t *gl, int id, sfVector2f pos);
void drop_item(globals_t *gl, loot_table_t *loot, sfVector2f pos);
void drop_enemy_loots(globals_t *gl, entity_t *entity);
void check_enemies_life(globals_t *gl);
void player_melee_weapon(entity_t *entity, weapon_t *weapon, globals_t *gl);
void use_distance_weapon(entity_t *entity,
    weapon_t *weapon, sfVector2f direction, globals_t *gl);
void remove_enemy(globals_t *gl, entity_t *entity);
loot_t *copy_item(globals_t *gl, int id);
void set_item_pos(loot_t *loot, sfVector2f pos);
void remove_item_from_word(globals_t *gl, loot_t *loot);
sfVector2f get_newposition(sfVector2f from, sfVector2f to, float speed);
entity_t *is_newpoint_colliding_entities(sfVector2f pos, entity_t **e);
int is_newpoint_colliding_walls(sfVector2f pos, sfConvexShape **w);
void move_bullet(globals_t *gl);
void play_melee_attack(globals_t *gl, sfVector2f pos, sfColor color);
int remove_bullet(globals_t *gl, bullet_t *bullet);
int add_bullet(globals_t *gl, sfVector2f dir, entity_t *shooter, int damage);

#endif
