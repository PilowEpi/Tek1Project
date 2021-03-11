/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Mathematical function
*/

#include <math.h>

#include "rpg.h"

float get_distance(sfVector2f pos1, sfVector2f pos2)
{
    float dx = powf(pos2.x - pos1.x, 2);
    float dy = powf(pos2.y - pos1.y, 2);
    float dist = sqrtf(dx + dy);

    return (dist);
}

float get_angle(sfVector2f player, sfVector2f mouse)
{
    sfVector2f third = (sfVector2f) {player.x + 50, player.y};
    float a = get_distance(player, third);
    float b = get_distance(player, mouse);
    float c = get_distance(third, mouse);
    float angle = acosf((powf(a, 2) + powf(b, 2) - powf(c, 2))/(2*a*b));

    angle = angle * 180/M_PI;
    if (mouse.y > player.y)
        angle = 180 + 180-angle;
    return (-angle);
}

float get_orientation(sfVector2f a, sfVector2f b, sfVector2f p)
{
    sfVector2f ab = (sfVector2f) {b.x - a.x, b.y - a.y};
    sfVector2f ap = (sfVector2f) {p.x - a.x, p.y - a.y};
    float scalaire = ab.x * ap.x + ab.y * ap.y;

    return (scalaire);
}

int is_colliding(sfConvexShape *shape, sfVector2f point)
{
    int pc = sfConvexShape_getPointCount(shape);
    int side = -1;
    float next_side = 0;
    sfVector2f shape_point1;
    sfVector2f shape_point2;
    sfTransform trans = sfConvexShape_getTransform(shape);

    for (int i = 0; i < pc; i++) {
        shape_point1 = sfConvexShape_getPoint(shape, i);
        shape_point1 = sfTransform_transformPoint(&trans, shape_point1);
        shape_point2 = i + 1 == pc ?  sfConvexShape_getPoint(shape, 0)
            : sfConvexShape_getPoint(shape, i + 1);
        shape_point2 = sfTransform_transformPoint(&trans, shape_point2);
        next_side = get_orientation(shape_point1, shape_point2, point);
        if (side == -1)
            side = next_side < 0 ? 0 : 1;
        if ((next_side < 0 ? 0 : 1) != side)
            return (0);
    }
    return (1);
}

int are_shape_colliding(sfConvexShape *shape1, sfConvexShape *shape2)
{
    int pc = sfConvexShape_getPointCount(shape2);
    sfVector2f point;
    sfTransform trans = sfConvexShape_getTransform(shape2);

    for (int i = 0; i < pc; i++) {
        point = sfConvexShape_getPoint(shape2, i);
        point = sfTransform_transformPoint(&trans, point);
        if (is_colliding(shape1, point))
            return (1);
    }
    return (0);
}