/*
** EPITECH PROJECT, 2019
** my_header
** File description:
** Header for the game engine
*/

#ifndef _RPG_ENGINE_H
#define _RPG_ENGINE_H

#include <SFML/Window.h>
#include <SFML/Graphics.h>

enum direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

enum weapon_type {
    DISTANCE,
    BODY
};

typedef struct weapon {
    enum weapon_type type;
    float damage;
    float range;
    float cooldown;
    sfClock *clock;
} weapon_t;

typedef struct loot_bank {
    int id;
    sfConvexShape **body;
} loot_t;

typedef struct loot_table {
    unsigned char id;
    unsigned char quantity;
    unsigned char prob;
} loot_table_t;

typedef struct entity_stat {
    float health;
    float speed;
    float rotationspeed;
    float armor;
} entity_stat_t;

typedef struct information {
    unsigned char type;
    sfVector2f pos;
    char id_obj;
} info_t;

typedef struct entity {
    int id;
    int state;
    sfConvexShape **body;
    sfVector2f pos;
    entity_stat_t *stat;
    loot_table_t **loot_table;
    weapon_t **weapon_list;
} entity_t;

typedef struct s_light {
    sfVector2f position;
    float radius;
    sfBool state;
} light_t;

typedef struct s_room {
    sfVector2i size;
    light_t **lights;
    entity_t **enemies;
    entity_t **npc;
    loot_t **items;
    info_t **info;
    sfConvexShape **walls;
    sfColor color;
    sfTexture *tex;
} room_t;

typedef struct entity_bank {
    entity_t **enemies_bank;
    entity_t **npc_bank;
    loot_t **loot;
} e_bank_t;

// Math utils
float get_angle(sfVector2f player, sfVector2f mouse);
float get_orientation(sfVector2f a, sfVector2f b, sfVector2f p);
int is_colliding(sfConvexShape *shape, sfVector2f point);
int are_shape_colliding(sfConvexShape *shape1, sfConvexShape *shape2);
float get_distance(sfVector2f pos1, sfVector2f pos2);

// entity drawing
int draw_entity(sfRenderWindow *window, entity_t *entity);

// Entity
entity_t *copy_entity(entity_t *entity);
int is_newpos_colliding_walls(sfConvexShape *shape, sfConvexShape **w);
sfConvexShape **copy_body(sfConvexShape **body);

// File handling
char *read_file(char *path);
int get_filesize(char *path);

// Room Getter
info_t *get_room_start(room_t *room);
info_t *get_room_end(room_t *room);

// Bank getter
int get_enemies_bank_size(e_bank_t *bank);
int get_loot_bank_size(e_bank_t *bank);
int add_weapon_to_entity(entity_t *entity, weapon_t *weapon);

#endif
