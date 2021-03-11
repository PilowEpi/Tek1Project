/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** particle engine header
*/

#ifndef _PAR_H
#define _PAR_H

#include <SFML/Graphics.h>
#include <SFML/Window.h>

#define DIR_DOWN   (0 << 0)
#define DIR_UP     (1 << 0)
#define DIR_LEFT   (1 << 1)
#define DIR_RIGHT  (1 << 1 | 1 << 0)
#define DIR_RANDOM (1 << 3)

#define vert(x) (x == DIR_UP || x == DIR_DOWN)

typedef struct fb {
    unsigned char *pixels;
    int width;
    int height;
} framebuffer_t;

typedef struct desc {
    sfColor *color;
    int *size;
    double offset;
    double *speed;
    double lifetime;
    double duration;
    int qty;
    char flags;
    sfIntRect reg_rect;
    sfVector2f *dir;
    sfVector2f *org;
    int dir_size;
    int org_size;
    char id;
} descriptor_t;

typedef struct pt {
    struct pt *next;
    struct pt *prev;
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    double life;
} point_t;

typedef struct sys {
    descriptor_t *desc;
    point_t *pt_head;
    double timer;
    sfTexture *tex;
    sfSprite *sprite;
} syst_t;

typedef struct par {
    sfRenderStates *state;
    sfShader *shader;
    syst_t **systems;
} part_t;

part_t *create_engine(sfVideoMode mode);
descriptor_t *create_descriptor(void);
syst_t *create_system(void);
point_t *create_particle(descriptor_t *desc);

void append_particle(syst_t *system, point_t *particle);
void delete_particle(syst_t *system, point_t *particle);

void append_system(part_t *engine, syst_t *system);
void remove_system(part_t *engine, syst_t *system);

void desc_append_color(descriptor_t *desc, sfColor color);
void desc_append_size(descriptor_t *desc, int n_size);
void desc_append_speed(descriptor_t *desc, double n_speed);

void desc_set_region_square(descriptor_t *desc, sfIntRect rect, char dir);
void desc_set_region_point(descriptor_t *desc, sfVector2f pt, char dir);

void set_pixel(framebuffer_t *fb, int x, int y, sfColor color);
void clear_fb(framebuffer_t *fb);
void update_engine(part_t *engine, double delta);
framebuffer_t *create_framebuffer(sfVideoMode mode);

void animate_engine(
    part_t *engine, double delta, sfRenderWindow *window, sfView *view);

#endif
