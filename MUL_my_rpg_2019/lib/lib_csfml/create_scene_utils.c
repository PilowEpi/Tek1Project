/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_scene_utils
*/

#include <stdlib.h>
#include "lib_csfml.h"
#include "struct_csfml.h"

void init_scene_sound(scene_t *scene, int *returned, const init_sound_t *sound)
{
    if (*returned == 84)
        return;
    scene->sound = malloc(sizeof(sound_t) * scene->nb_sound);
    if (!scene->sound) {
        *returned = 84;
        return;
    }
    for (int i = 0; i < scene->nb_sound; i++) {
        if (create_sound(&scene->sound[i], &sound[i])) {
            *returned = 84;
            return;
        }
    }
}

void init_scene_img(scene_t *scene, int *returned, const init_sprite_t *sprite)
{
    if (*returned == 84) {
        return;
    }
    scene->sprite = malloc(sizeof(sprite_t) * scene->nb_sprite);
    if (!scene->sprite) {
        *returned = 84;
        return;
    }
    for (int i = 0; i < scene->nb_sprite; i++) {
        if (init_sprite(&scene->sprite[i], &sprite[i])) {
            *returned = 84;
            return;
        }
    }
}

void init_scene_button(scene_t *scene, int *returned, const init_but_t *button)
{
    if (*returned == 84)
        return;
    scene->button = malloc(sizeof(button_t) * scene->nb_button);
    if (!scene->button) {
        *returned = 84;
        return;
    }
    for (int i = 0; i < scene->nb_button; i++) {
        if (init_button(&scene->button[i], &button[i])) {
            *returned = 84;
            return;
        }
    }
}

void init_scene_text(scene_t *scene, int *returned, const init_text_t *text)
{
    if (*returned == 84)
        return;
    scene->text = malloc(sizeof(text_t) * scene->nb_text);
    if (!scene->text) {
        *returned = 84;
        return;
    }
    for (int i = 0; i < scene->nb_text; i++) {
        if (init_text(&scene->text[i], &text[i])) {
            *returned = 84;
            return;
        }
    }
}