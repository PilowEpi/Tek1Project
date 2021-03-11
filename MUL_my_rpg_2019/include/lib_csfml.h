/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lib_csfml
*/

#ifndef LIB_CSFML_H_
#define LIB_CSFML_H_

/*

    Library created by Mathieu R. for MUL_my_rpg_2019

*/

// EXIT EXIT_FAILURE : -1
// EXIT EXIT_SUCCESS : 1

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "struct_csfml.h"

// [Window Function]

sfRenderWindow *create_window(sfVideoMode mode, char *title, sfUint32 style);
sfVideoMode create_video_mode(int width, int height, int bits_per_pixel);

// [Sprite Function]

int init_sprite(sprite_t *sprite, const init_sprite_t *sprite_data);
int create_sprite(sprite_t *sprite);
int init_sprite_texture(sprite_t *sprite, char *pathname);
void init_vector(sprite_t *sprite, float x, float y);

// [Button Function]

int init_button_data(button_t *button, const init_but_t *but_data);
void init_button_rect(button_t *button, const init_but_t *but_data);
int init_button(button_t *button, const init_but_t *but_data);

// [Text Function]

int init_text(text_t *text, const init_text_t *text_data);

// [Music Function]

int create_sound(sound_t *sound, const init_sound_t *sound_data);

// [Scene Function]

void init_scene_img(scene_t *scene, int *returned, const init_sprite_t *sprite);
void init_scene_button(scene_t *scene, int *returned, const init_but_t *button);
void init_scene_text(scene_t *scene, int *returned, const init_text_t *text);
void init_scene_sound(scene_t *scene, int *returned, const init_sound_t *sound);
void initialize_scene(scene_t *scene, int *returned,
const init_scene data_scene);

#endif /* !LIB_CSFML_H_ */