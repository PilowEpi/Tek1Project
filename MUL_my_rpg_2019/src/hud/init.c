/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** hud init
*/

#include <stdlib.h>

#include "my.h"
#include "rpg.h"

int update_armor(hud_t *hud, float change)
{
    hud->armor = hud->armor + change;
    if (hud->armor > hud->max_armor)
        hud->armor = hud->max_armor;
    if (hud->armor < 0)
        hud->armor = 0;
    sfConvexShape_setScale(hud->armor_bar,
            (sfVector2f) {(hud->armor / hud->max_armor) * 0.95, 0.8});
    if (hud->armor == 0)
        return (1);
    return (0);
}

int update_life(hud_t *hud, float change)
{
    if (hud->armor != 0 && change < 0) {
        hud->armor = hud->armor + change;
        change = hud->armor < 0 ? hud->armor : 0;
        hud->armor = hud->armor < 0 ? 0 : hud->armor;
        sfConvexShape_setScale(hud->armor_bar,
            (sfVector2f) {(hud->armor / hud->max_armor) * 0.95, 0.8});
        if (change == 0)
            return (0);
    }
    hud->life = hud->life + change;
    if (hud->life > hud->max_life)
        hud->life = hud->max_life;
    if (hud->life <= 0)
        hud->life = 0;
    sfConvexShape_setScale(hud->life_bar,
        (sfVector2f) {(hud->life / hud->max_life) * 0.95, 0.8});
    if (hud->life == 0)
        return (1);
    return (0);
}

void init_xp(hud_t *hud, globals_t *gl)
{
    hud->xp = 1;
    hud->xp_next_level = 100;
    hud->xp_bar = sfConvexShape_create();
    hud->x_container = sfConvexShape_create();
    set_points(hud->xp_bar, (sfFloatRect) {0, 0, 200, 50});
    set_points(hud->x_container, (sfFloatRect) {0, 0, 200, 50});
    sfConvexShape_setFillColor(hud->x_container,
        sfColor_fromRGB(50, 50, 50));
    sfConvexShape_setFillColor(hud->xp_bar, sfGreen);
    sfConvexShape_setScale(hud->xp_bar,
        (sfVector2f) {(hud->xp / hud->xp_next_level) * 0.95, 0.8});
    sfConvexShape_setPosition(hud->x_container, (sfVector2f) {
        (gl->mode.width) / 2, gl->mode.height - 190});
    sfConvexShape_setPosition(hud->xp_bar, (sfVector2f) {
        (gl->mode.width) / 2 + 5, gl->mode.height - 190 + 5});
}

void init_xp_text(hud_t *hud, globals_t *gl)
{
    sfFont *font = sfFont_createFromFile("assets/font/sweet_purple.ttf");

    hud->level = 0;
    hud->a_level = my_int_to_str(hud->level);
    hud->text_level = sfText_create();
    sfText_setFont(hud->text_level, font);
    sfText_setColor(hud->text_level, sfWhite);
    sfText_setString(hud->text_level, hud->a_level);
    sfText_setPosition(hud->text_level,  (sfVector2f) {
        (gl->mode.width + 170) / 2 + 5, gl->mode.height - 190 + 5});
}

void init_hud(globals_t *gl)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->inv_slots = init_inventory(gl->mode);
    sfConvexShape_setFillColor(hud->inv_slots[0],
        sfColor_fromRGB(170, 170, 170));
    hud->inv_contains = malloc(sizeof(loot_t) * SLOT_NB);
    for (int i = 0; i < SLOT_NB; i++)
        hud->inv_contains[i] = 0;
    hud->slot_selected = 0;
    init_life(hud, gl);
    init_xp(hud, gl);
    init_xp_text(hud, gl);
    init_armor(hud, gl);
    gl->hud = hud;
}
