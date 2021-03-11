/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Allow entity to move
*/

#include "rpg.h"

sfVector2f get_newposition(sfVector2f from, sfVector2f to, float speed)
{
    float dx = to.x - from.x;
    float dy = to.y - from.y;
    float steps = (dx < 0 ? -dx : dx) > (dy < 0 ? -dy : dy) ?
        (dx < 0 ? -dx : dx) : (dy < 0 ? -dy : dy);
    float xinc = dx / steps;
    float yinc = dy / steps;

    if (steps == 0)
        return (from);
    if (steps < speed)
        return (to);
    for (int i = 0; i < speed; i++) {
        from.x += xinc;
        from.y += yinc;
    }
    return (from);
}

int move_entity(entity_t *entity, sfVector2f to, int speed, globals_t *gl)
{
    sfVector2f from = entity->pos;
    sfVector2f next_position = get_newposition(from, to, speed);
    sfConvexShape **walls = gl->rooms[gl->room_index]->walls;

    if (!entity || !entity->body)
        return (1);
    for (int i = 0; entity->body && entity->body[i]; i++) {
        sfConvexShape_setPosition(entity->body[i], next_position);
        if (!is_newpos_colliding_walls(entity->body[i], walls))
            continue;
        for (int y = 0; entity->body && entity->body[y]; y++) {
            sfConvexShape_setPosition(entity->body[y], entity->pos);
        }
        return (1);
    }
    move_camera(gl);
    entity->pos = next_position;
    return (0);
}

int is_pos_inwall(sfVector2f pos, sfConvexShape **walls)
{
    for (int i = 0; walls && walls[i]; i++) {
        if (is_colliding(walls[i], pos))
            return (1);
    }
    return (0);
}

int move_enemy(entity_t *entity, globals_t *gl)
{
    sfVector2f player_position = gl->player->pos;
    sfVector2f enemy_position = entity->pos;

    while (!(enemy_position.x == player_position.x &&
        player_position.y == enemy_position.y)) {
        enemy_position = get_newposition(enemy_position, player_position, 1);
        if (is_pos_inwall(enemy_position, gl->rooms[gl->room_index]->walls))
            return (1);
    }
    if (entity->id % 2 != 0)
        return (move_entity(entity, player_position, 5, gl));
    if (get_distance(player_position, entity->pos)
        <= entity->weapon_list[0]->range)
        return (0);
    move_entity(entity, player_position, 5, gl);
    return (0);
}