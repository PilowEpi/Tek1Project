/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Launch map read light
*/

#include <stdlib.h>

#include "rpg.h"

light_t *init_new_light(sfVector2f pos, short radius, char status)
{
    light_t *light = malloc(sizeof(light_t));

    if (!light)
        return (light);
    light->position = pos;
    light->radius = (float) radius;
    light->state = (status == 0) ? sfFalse : sfTrue;
    return (light);
}

int add_light_to_room(room_t *room, sfVector2f pos, short radius, char status)
{
    int lc = 0;
    light_t **new_lights;

    for (lc = 0; room->lights && room->lights[lc]; lc++);
    new_lights = malloc(sizeof(light_t *) * (lc + 2));
    if (!new_lights)
        return (1);
    for (int i = 0; i < lc; i++)
        new_lights[i] = room->lights[i];
    new_lights[lc] = init_new_light(pos, radius, status);
    new_lights[lc + 1] = 0;
    if (!new_lights[lc])
        return (1);
    if (room->lights)
        free(room->lights);
    room->lights = new_lights;
    return (0);
}

int add_light(dfile_t *a_data, room_t *room, int *i)
{
    unsigned char *data = a_data->data;
    short posi[2];
    short radius;
    char st;
    sfVector2f pos;

    data = data + *i;
    if (a_data->data_size < *i + 7)
        return (-(a_data->data_size));
    radius = data[0] << 8;
    radius |= data[1];
    st = data[2];
    posi[0] = data[3] << 8;
    posi[0] |= data[4];
    posi[1] = data[5] << 8;
    posi[1] |= data[6];
    pos = (sfVector2f) {(float) posi[0], (float) posi[1]};
    if (add_light_to_room(room, pos, radius, st))
        return (-(a_data->data_size));
    return (7);
}
