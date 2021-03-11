/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** initialize_scene
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "struct_defender.h"
#include "dico_defender.h"

void init_scene_img(scene_t *scene, int *returned, const init_sprite_t *sprite)
{
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

void initialize_scene(scene_t *scene, int *returned,
const init_scene data_scene)
{
    int nb_sprite = 0;
    int nb_button = 0;
    int nb_text = 0;

    if (*returned == 84)
        return;
    for (; data_scene.sprite[nb_sprite].path; nb_sprite++);
    for (; data_scene.button[nb_button].path; nb_button++);
    if (data_scene.text != NULL) {
        for (; data_scene.text[nb_text].text; nb_text++);
        scene->nb_text = nb_text;
        init_scene_text(scene, returned, data_scene.text);
    }
    scene->nb_sprite = nb_sprite;
    scene->nb_button = nb_button;
    init_scene_img(scene, returned, data_scene.sprite);
    init_scene_button(scene, returned, data_scene.button);
}