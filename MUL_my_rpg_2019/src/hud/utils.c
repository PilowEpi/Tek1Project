/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** hud utils functions
*/

#include "rpg.h"

void set_points(sfConvexShape *shape, sfFloatRect rect)
{
    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, (sfVector2f) {rect.left, rect.top});
    sfConvexShape_setPoint(shape, 1, (sfVector2f) {rect.left, rect.height});
    sfConvexShape_setPoint(shape, 2, (sfVector2f) {rect.width, rect.height});
    sfConvexShape_setPoint(shape, 3, (sfVector2f) {rect.width, rect.top});
}
