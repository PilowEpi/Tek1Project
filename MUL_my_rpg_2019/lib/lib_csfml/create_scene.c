/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_scene
*/

#include "lib_csfml.h"
#include "struct_csfml.h"

void count_object(scene_t *scene, const init_scene data_scene)
{
    scene->nb_sprite = 0;
    scene->nb_button = 0;
    scene->nb_sound = 0;
    scene->nb_text = 0;
    if (data_scene.sprite)
        for (; data_scene.sprite[scene->nb_sprite].path;)
            scene->nb_sprite++;
    if (data_scene.button)
        for (; data_scene.button[scene->nb_button].path;)
            scene->nb_button++;
    if (data_scene.text)
        for (; data_scene.text[scene->nb_text].text;)
            scene->nb_text++;
    if (data_scene.sound)
        for (; data_scene.sound[scene->nb_sound].pathname;)
            scene->nb_sound++;
}

void initialize_scene(scene_t *scene, int *returned,
const init_scene data_scene)
{
    if (*returned == 84) {
        return;
    }
    count_object(scene, data_scene);
    if (data_scene.text)
        init_scene_text(scene, returned, data_scene.text);
    if (data_scene.button)
        init_scene_button(scene, returned, data_scene.button);
    if (data_scene.sprite)
        init_scene_img(scene, returned, data_scene.sprite);
    if (data_scene.sound)
        init_scene_sound(scene, returned, data_scene.sound);
}