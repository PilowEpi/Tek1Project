/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Bullet handling
*/

#include <stdlib.h>

#include "rpg.h"

int check_player(globals_t *gl, bullet_t *bullet)
{
    entity_t *player = gl->player;

    if (is_newpoint_colliding_walls(bullet->pos, player->body) &&
        bullet->shooter != gl->player) {
        update_life(gl->hud, -bullet->damage);
        return (1);
    }
    return (0);
}

void check_bullet(globals_t *gl)
{
    bullet_t *bullet;
    entity_t *entity;

    for (int i = 0; gl->bullet && gl->bullet[i]; i++) {
        bullet = gl->bullet[i];
        entity = is_newpoint_colliding_entities(
            bullet->pos, gl->rooms[gl->room_index]->enemies);
        if (bullet->pos.x == bullet->direction.x &&
            bullet->pos.y == bullet->direction.y || check_player(gl, bullet)) {
            remove_bullet(gl, bullet);
            i = -1;
            continue;
        }
        if (!entity)
            continue;
        if (entity && entity == bullet->shooter)
            continue;
        entity->stat->health -= bullet->damage;
        play_melee_attack(gl, entity->pos, sfYellow);
        remove_bullet(gl, bullet);
        i = -1;
    }
}

int add_bullet(globals_t *gl, sfVector2f dir, entity_t *shooter, int damage)
{
    bullet_t *bullet = malloc(sizeof(bullet_t));
    bullet_t **new;
    int lc = 0;
    bullet->direction = dir;
    bullet->pos = shooter->pos;
    bullet->shooter = shooter;
    bullet->damage = damage;
    for (lc = 0; gl->bullet && gl->bullet[lc]; lc++);
    new = malloc(sizeof(bullet_t *) * (lc + 2));
    if (!new)
        return (1);
    for (int i = 0; i < lc; i++)
        new[i] = gl->bullet[i];
    new[lc] = bullet;
    new[lc + 1] = 0;
    if (!new[lc])
        return (1);
    if (gl->bullet)
        free(gl->bullet);
    gl->bullet = new;
    return (0);
}

int remove_bullet(globals_t *gl, bullet_t *bullet)
{
    bullet_t **new;
    int lc = 0;
    int index = 0;

    for (lc = 0; gl->bullet && gl->bullet[lc]; lc++);
    new = malloc(sizeof(bullet_t *) * (lc));
    if (!new)
        return (1);
    for (int i = 0; i < lc; i++)
        if (bullet != gl->bullet[i])
            new[index++] = gl->bullet[i];
    new[index] = 0;
    if (gl->bullet)
        free(gl->bullet);
    gl->bullet = new;
    return (0);
}

void bullet_particle(globals_t *gl, sfVector2f pos)
{
    syst_t *new = create_system();

    desc_set_region_point(new->desc, pos, DIR_RANDOM);
    new->desc->size[0] = 100;
    new->desc->speed[0] = 0;
    new->desc->duration = 0.25;
    new->desc->lifetime = 0.25;
    new->desc->qty = 1;
    new->desc->color = malloc(sizeof(sfColor));
    if (new->desc->color == NULL)
        return;
    new->desc->color[0] = sfYellow;
    append_system(gl->particle, new);
}

void move_bullet(globals_t *gl)
{
    sfVector2f new_pos;
    bullet_t *bullet;
    sfConvexShape **walls = gl->rooms[gl->room_index]->walls;

    for (int i = 0; gl->bullet && gl->bullet[i]; i++) {
        bullet = gl->bullet[i];
        new_pos = get_newposition(bullet->pos, bullet->direction, 10);
        bullet->pos = new_pos;
        bullet_particle(gl, new_pos);
    }
    for (int i = 0; gl->bullet && gl->bullet[i]; i++) {
        bullet = gl->bullet[i];
        if (!is_newpoint_colliding_walls(bullet->pos, walls))
            continue;
        remove_bullet(gl, bullet);
        i = 0;
    }
    check_bullet(gl);
}