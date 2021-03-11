/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** struct_csfml
*/

#ifndef STRUCT_CSFML_H_
#define STRUCT_CSFML_H_

/*

    Library created by Mathieu R. for MUL_my_rpg_2019

*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>

// Static Non-Build Struct

typedef struct s_text {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
}text_t;

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

typedef struct s_sound
{
    sfSound *sound;
    sfSoundBuffer *buffer;
}sound_t;

typedef struct s_button
{
    sprite_t b_sprite;
    sfFloatRect rect;
    sfIntRect rect_tab[3];
    int current_rect;
    int (*fct) (void *data);
}button_t;


typedef struct s_scene
{
    int nb_sprite;
    int nb_button;
    int nb_text;
    int nb_sound;
    sprite_t *sprite;
    button_t *button;
    text_t *text;
    sound_t *sound;
    sfEvent event;
}scene_t;

// Static Pre-Build Struct

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
    int (*fct) (void *data);
    float rect_height;
    float rect_width;
    sfIntRect rect_tab[3];
}init_but_t;

typedef struct s_init_sound
{
    char *pathname;
    int repeat;
}init_sound_t;

typedef struct s_init_scene
{
    int type_scene;
    const init_but_t *button;
    const init_sprite_t *sprite;
    const init_text_t *text;
    const init_sound_t *sound;
}init_scene;

#endif /* !STRUCT_CSFML_H_ */