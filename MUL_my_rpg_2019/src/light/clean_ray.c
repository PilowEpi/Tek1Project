/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** Add lasts points and sort raycasts
*/

#include <math.h>

#include "engine.h"
#include "rpg.h"

float get_cast_angle(sfVector2f p1, sfVector2f p2, sfVector2f p3)
{
    float angle = atan2f(p3.y - p1.y, p3.x - p1.x) -
        atan2f(p2.y - p1.y, p2.x - p1.x);

    return (angle);
}

float cmp_casts(sfVector2f pos1, sfVector2f pos2, sfVector2f light)
{
    return (get_cast_angle(light,
        (sfVector2f) {0, 0}, pos1) -
        get_cast_angle(light, (sfVector2f) {0, 0}, pos2));
}

void sort_casts(sfVector2f *array, int len, sfVector2f pos)
{
    sfVector2f temp;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (cmp_casts(array[j], array[i], pos) < 0) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void clean_rays(sfVector2f *casts, light_t *light, room_t *room)
{
    int pt_size = get_point_counts(room);

    do_raycast(&casts[pt_size - 4], light->position,
        (sfVector2f) {0, 0}, room);
    do_raycast(&casts[pt_size - 3], light->position,
        (sfVector2f) {1920, 0}, room);
    do_raycast(&casts[pt_size - 2], light->position,
        (sfVector2f) {0, 1080}, room);
    do_raycast(&casts[pt_size - 1], light->position,
        (sfVector2f) {1920, 1080}, room);
    sort_casts(casts, pt_size, light->position);
}
