/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** intersections
*/

#include <math.h>

#include "engine.h"

sfVector2f get_inter(sfVector2f from, sfVector2f to, sfVector2f f_p,
    sfVector2f t_p)
{
    float r_dx = to.x - from.x;
    float r_dy = to.y - from.y;
    float s_dx = t_p.x - f_p.x;
    float s_dy = t_p.y - f_p.y;
    float r_mag = sqrtf(r_dx * r_dx + r_dy * r_dy);
    float s_mag = sqrtf(s_dx * s_dx + s_dy * s_dy);
    float t1;
    float t2;

    if (r_dx / r_mag == s_dx / s_mag && r_dy / r_mag == s_dy / s_mag)
        return ((sfVector2f) {-1, -1});
    t2 = (r_dx * (f_p.y - from.y) + r_dy *
        (from.x - f_p.x)) / (s_dx * r_dy - s_dy * r_dx);
    t1 = (f_p.x + s_dx * t2 - from.x) / r_dx;
    if (t1 < 0 || t2 < 0 || t2 > 1)
        return ((sfVector2f) {-1, -1});
    return ((sfVector2f) {from.x + r_dx * t1, from.y + r_dy * t1});
}
