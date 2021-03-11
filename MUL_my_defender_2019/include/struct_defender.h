/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** struct_defender.h
*/

#ifndef STRUCT_DEFENDER_H
#define STRUCT_DEFENDER_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define MAP_SIZE 32

enum hud_state {
    TOWER_CELL,
    CASTLE_CELL,
    EMPTY_CELL,
    PORTAL_CELL,
    NOT_A_CELL
};

enum world_type {
    FOREST,
    DESERT,
    ICE,
    VOLCANO
};

enum enemy_type {
    MARVIN,
    GOLEM,
    ORC,
    THIEF,
    BAT,
    YETI,
    TRUMP
};

enum tower_type {
    ARCHER,
    BOMB,
    MAGIC,
    SLOW
};

typedef enum e_type_scene
{
    MENU,
    OPTION,
    LEVELS,
    IN_GAME,
    PAUSE,
    END_GAME,
    LAST
}type_scene_t;

typedef enum e_state
{
    WIN,
    LOSE,
    OTHER
}state_t;

typedef struct s_sprite
{
    char *pathname;
    sfSprite *img;
    sfTexture *texture;
    sfVector2f speed;
    sfIntRect *rect;
    sfVector2f vect;
    sfVector2f init;
}sprite_t;

typedef struct s_text {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
}text_t;

typedef struct s_button
{
    sprite_t b_sprite;
    sfFloatRect rect;
    sfIntRect rect_tab[3];
    int current_rect;
    int (*fct) (void *data, void *win, void *game);
}button_t;

typedef struct s_window
{
    sfRenderWindow *window;
    sfView *minimap;
    sfView *hud;
    type_scene_t type_scene;
    int width;
    int heigth;
    int frame_limit;
    float scale_ratio;
    sfVector2i mouse_vect;
    sfVector2u win_size;
}window_t;

typedef struct s_scene
{
    int nb_sprite;
    int nb_button;
    int nb_text;
    sprite_t *sprite;
    button_t *button;
    text_t *text;
    sfEvent event;
}scene_t;

typedef struct s_data
{
    enum world_type type;
    int level_choose;
    float difficulty;
}data_t;

typedef struct spritesheet {
    int width;
    int margin;
    int sprite_count;
    sfTexture *texture;
} spritesheet_t;

typedef struct animation_s {
    sfBool repeat;
    sfSprite *sprite;
    spritesheet_t *spritesheet;
    float duration;
    sfClock *clock;
    int state;
} animation_t;

typedef struct s_portal {
    sfVector2i pos;
    sfSprite *sprite;
    float spawn_rate;
    sfClock *spawn;
    struct s_portal *next;
} portal_t;

typedef struct s_enemy
{
    enum enemy_type type;
    float health;
    float damage;
    float speed;
    sfVector2f pos;
    animation_t *animation;
    sfClock *attack_clock;
    struct s_enemy *next;
} enemy_t;

typedef struct s_tower
{
    enum tower_type type;
    sfVector2i pos;
    sfSprite *sprite;
    int level;
    float attack_rate;
    sfClock *attack_clock;
    struct s_tower *next;
} tower_t;

typedef struct shoot {
    sfSprite *sprite;
    sfVector2f from;
    tower_t *tower;
    enemy_t *to;
    struct shoot *next;
} shoot_t;

typedef struct s_level
{
    enum world_type type;
    enum hud_state hud;
    int wave;
    float difficulty;
    float score;
    float gold;
    float health;
    tower_t *tower_list;
    enemy_t *enemy_list;
    portal_t *portal_list;
    shoot_t *shoot;
    sfSprite *background;
    sfSprite *castle;
    sfClock *level_clock;
    sfClock *movement_clock;
    sfVector2i tile_s;
} level_t;

typedef struct game_texture
{
    animation_t **walk_ssa;
    animation_t **attack_ssa;
    animation_t **die_ssa;
    spritesheet_t **walk_sss;
    spritesheet_t **attack_sss;
    spritesheet_t **die_sss;
    sfTexture **walk_ss;
    sfTexture **attack_ss;
    sfTexture **die_ss;
    sfTexture **towers;
    sfTexture **backgrounds;
    sfTexture **castles;
    sfTexture *portal;
    sfTexture **projectile;
} game_texture_t;

typedef struct s_game
{
    int nb_scene;
    scene_t *def_scene;
    sfClock *clock;
    sfTime Time;
    double seconds;
    data_t data;
    game_texture_t *texture;
    level_t *level;
    sfView *view;
    sfMusic *ambiance;
    sfSoundBuffer **buffer;
    sfSound **sound_effect;
}game_t;

// [DICO]

typedef struct s_init_text
{
    char *text;
    char *font;
    int size;
    int x_coor;
    int y_coor;
    int red_c;
    int green_c;
    int blue_c;
}init_text_t;

typedef struct s_init_sprite
{
    char *path;
    int x_coor;
    int y_coor;
}init_sprite_t;

typedef struct s_init_but
{
    char *path;
    int x_coor;
    int y_coor;
    int (*fct) (void *data, void *win, void *game);
    float rect_height;
    float rect_width;
    sfIntRect rect_tab[3];
}init_but_t;

typedef struct s_draw
{
    type_scene_t type_scene;
    int (*draw) (window_t *win, game_t *game);
}draw_t;

typedef struct s_init_scene
{
    type_scene_t type_scene;
    const init_but_t *button;
    const init_sprite_t *sprite;
    const init_text_t *text;
}init_scene;

typedef struct s_init_hud
{
    enum hud_state state;
    int sprite_count;
    int button_count;
} hud_stat_t;

typedef struct spritesheet_info {
    int type;
    int width;
    int margin;
    int sprite_count;
    float duration;
} spritesheet_info_t;

#endif
