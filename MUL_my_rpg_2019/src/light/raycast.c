/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** raycast
*/

#include <stdlib.h>
#include <math.h>

#include "engine.h"
#include "rpg.h"

void do_raycast(sfVector2f *buf, sfVector2f from, sfVector2f to, room_t *room)
{
    sfVector2f bound;
    int written = 0;
    sfFloatRect rect = {from.x, from.y, to.x, to.y};

    for (int i = 0; room->walls[i] != 0; i++)
        check_raycast(buf, rect, &written, room->walls[i]);
    if (written)
        return;
    if (check_bound(buf, from, to, (sfFloatRect) {0, 0, 1920, 0}))
        return;
    if (check_bound(buf, from, to, (sfFloatRect) {0, 0, 0, 1080}))
        return;
    if (check_bound(buf, from, to, (sfFloatRect) {1920, 0, 1920, 1080}))
        return;
    check_bound(buf, from, to, (sfFloatRect) {0, 1080, 1920, 1080});
}

void triple_raycast(
    sfVector2f *buf, sfVector2f from, sfVector2f to, room_t *room)
{
    float angle = 0.00001f;
    sfVector2f small_to = {cosf(angle) *
        (to.x - from.x) - sinf(angle) * (to.y - from.y) + from.x,
        sinf(angle) *
        (to.x - from.x) + cosf(angle) * (to.y - from.y) + from.y};
    sfVector2f big_to = {cosf(-angle)
    * (to.x - from.x) - sinf(-angle) * (to.y - from.y) + from.x,
    sinf(-angle)
    * (to.x - from.x) + cosf(-angle) * (to.y - from.y) + from.y};

    do_raycast(&(buf[0]), from, small_to, room);
    do_raycast(&(buf[1]), from, to, room);
    do_raycast(&(buf[2]), from, big_to, room);
}

sfVector2f *get_raycasts(light_t *light, room_t *room, int sub_i, int main_i)
{
    int pt_size = get_point_counts(room);
    sfConvexShape *current_shape = NULL;
    int cs_pt_count = 0;
    sfVector2f dir;
    sfVector2f *casts = malloc(sizeof(sfVector2f) * pt_size);

    current_shape = room->walls[main_i];
    cs_pt_count = sfConvexShape_getPointCount(current_shape);
    for (int i = 0; i < pt_size - 4; i += 3){
        dir = sfConvexShape_getPoint(current_shape, sub_i);
        triple_raycast(&(casts[i]), light->position, dir, room);
        sub_i++;
        if (sub_i >= cs_pt_count && i + 4 < pt_size - 4){
            current_shape = room->walls[++main_i];
            cs_pt_count = sfConvexShape_getPointCount(current_shape);
            sub_i = 0;
        }
    }
    clean_rays(casts, light, room);
    return (casts);
}
