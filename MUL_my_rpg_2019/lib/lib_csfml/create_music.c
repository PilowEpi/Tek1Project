/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_music
*/

#include "lib_csfml.h"
#include "struct_csfml.h"

int create_sound(sound_t *sound, const init_sound_t *sound_data)
{
    sound->sound = sfSound_create();
    sound->buffer = sfSoundBuffer_createFromFile(sound_data->pathname);
    if (!sound->buffer)
        return (-1);
    sfSound_setBuffer(sound->sound, sound->buffer);
    if (sound_data->repeat == 1)
        sfSound_setLoop(sound->sound, 1);
    return (0);
}