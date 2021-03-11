/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** light init
*/

#include <stdlib.h>

#include "engine.h"
#include "rpg.h"

int alloc_poly_light(sfConvexShape ***poly, room_t *room, light_t *light)
{
    int w_size = 0;
    int i = 0;

    while (room->walls[i] != 0)
        w_size += sfConvexShape_getPointCount(room->walls[i++]) * 3;
    *poly = malloc(sizeof(sfConvexShape *) * (w_size + 5));
    if (!*poly)
        return (1);
    for (int i = 0; i < w_size + 5; i++)
        (*poly)[i] = 0;
    return (0);
}

sfConvexShape ***alloc_polygones(room_t *room)
{
    int l_size = 0;
    sfConvexShape ***res = 0;

    while (room->lights && room->lights[l_size] != 0)
        l_size++;
    if (!(res = malloc(sizeof(sfConvexShape **) * (l_size + 1))))
        return (0);
    res[l_size] = 0;
    for (int i = 0; i < l_size; i++)
        if (alloc_poly_light(&res[i], room, room->lights[i]))
            return (0);
    return (res);
}

void free_polygones(sfConvexShape ***poly)
{
    for (int i = 0; poly[i] != 0; i++){
        for (int j = 0; poly[i][j] != 0; j++){
            sfConvexShape_destroy(poly[i][j]);
        }
        free(poly[i]);
    }
    free(poly);
}
