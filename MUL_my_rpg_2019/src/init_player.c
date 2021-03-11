/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** Init assets
*/

#include <stdio.h>
#include <stdlib.h>

#include "rpg.h"
#include "engine.h"
#include "my.h"

int init_player_body(sfConvexShape *shape, sfVector2f pos)
{
    sfConvexShape_setPointCount(shape, 4);
    sfConvexShape_setPoint(shape, 0, (sfVector2f) {0, 0});
    sfConvexShape_setPoint(shape, 1, (sfVector2f) {0, 100});
    sfConvexShape_setPoint(shape, 2, (sfVector2f) {100, 100});
    sfConvexShape_setPoint(shape, 3, (sfVector2f) {100, 0});
    sfConvexShape_setFillColor(shape, sfWhite);
    sfConvexShape_setOrigin(shape, (sfVector2f) {50, 50});
    sfConvexShape_setPosition(shape, pos);
    return (0);
}

int init_player(globals_t *room)
{
    info_t *start = get_room_start(room->rooms[0]);
    sfVector2f pos = start ? start->pos : (sfVector2f) {0, 0};

    if (!start) {
        return (1);
    }
    room->player = malloc(sizeof(entity_t));
    if (!room->player)
        return (1);
    room->player->body = malloc(sizeof(sfConvexShape *) * 2);
    if (!room->player->body)
        return (1);
    room->player->body[0] = sfConvexShape_create();
    if (!room->player->body[0])
        return (1);
    init_player_body(room->player->body[0], pos);
    room->player->body[1] = 0;
    room->player->weapon_list = 0;
    room->player->pos = pos;
    return (0);
}

void init_text_end_room(globals_t *gl)
{
    gl->end_room = sfText_create();
    gl->quest = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/sweet_purple.ttf");

    gl->end_room = sfText_create();
    sfText_setFont(gl->end_room, font);
    sfText_setColor(gl->end_room, sfRed);
    sfText_setString(gl->end_room, "Press E to go to next room !\n");
    sfText_setFont(gl->quest, font);
    sfText_setColor(gl->quest, sfWhite);
    sfText_setString(gl->quest, "Quest: Get out of the Prison !");
    sfText_setPosition(gl->quest, (sfVector2f) {10, 10});
}

void init_engine(globals_t *gl)
{
    gl->bank = get_enemies("assets/enemy.dat");
    if (!gl->bank)
        my_printf("Error in the Enemies / loot library !\n");
    gl->rooms = get_rooms("assets/map.dat", gl);
    if (!gl->rooms) {
        my_printf("Error in the Map you can't play with this map !\n");
    }
    show_rooms_information(gl->rooms);
    show_bank_information(gl->bank);
    init_text_end_room(gl);
    gl->player = NULL;
    gl->room_index = 0;
    gl->bullet = NULL;
    if (init_player(gl)) {
        my_printf("Error in the Map you can't play with this map !\n");
    }
}

void init_lights_at_room(globals_t *gl, int index)
{
    int lights_count = 0;
    sfGlslVec3 *lights = 0;

    while (gl->rooms[index]->lights[lights_count] != 0)
        lights_count++;
    if (!(lights = malloc(sizeof(sfGlslVec3) * lights_count)))
        return;
    for (int i = 0; i < lights_count; i++)
        lights[i] = (sfGlslVec3) {
            gl->rooms[index]->lights[i]->position.x,
            gl->rooms[index]->lights[i]->position.y,
            gl->rooms[index]->lights[i]->radius
        };
    sfShader_setVec3UniformArray(gl->shader, "u_lights", lights, lights_count);
    sfShader_setIntUniform(gl->shader, "u_lights_count", lights_count);
    gl->light_polys = alloc_polygones(gl->rooms[index]);
    update_lights(gl->light_polys, gl);
    gl->light_shader_obj = lights;
}