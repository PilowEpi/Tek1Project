/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** update light polygones
*/

#include <stdlib.h>

#include "engine.h"
#include "rpg.h"

void set_poly_to(sfConvexShape **to, light_t *light, sfVector2f first,
    sfVector2f second)
{
    if (!*to)
        *to = sfConvexShape_create();
    sfConvexShape_setPointCount(*to, 3);
    sfConvexShape_setPoint(*to, 0, light->position);
    sfConvexShape_setPoint(*to, 1, first);
    sfConvexShape_setPoint(*to, 2, second);
}

void update_single(sfConvexShape **poly, room_t *room, light_t *light)
{
    sfVector2f *raycasts = get_raycasts(light, room, 0, 0);
    int points = get_point_counts(room);

    for (int i = 0; i < points - 1; i++){
        set_poly_to(&(poly[i]), light, raycasts[i], raycasts[i + 1]);
    }
    set_poly_to(&poly[points - 1], light, raycasts[0], raycasts[points - 1]);
    for (int i = points; poly[i] != 0; i++)
        sfConvexShape_destroy(poly[i]);
    free(raycasts);
}

void update_lights(sfConvexShape ***poly, globals_t *gl)
{
    for (int i = 0; poly[i] != 0; i++)
        update_single(poly[i], gl->rooms[gl->room_index],
            gl->rooms[gl->room_index]->lights[i]);
}
