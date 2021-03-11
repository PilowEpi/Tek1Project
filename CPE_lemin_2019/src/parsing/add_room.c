/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** add_room
*/

#include <stdlib.h>

#include "lemin.h"
#include "my.h"

int get_command(char *info, int prev)
{
    if (!info)
        return (84);
    if (my_strncmp("##start", info, 7) == 0)
        return (START);
    else if (my_strncmp("##end", info, 5) == 0)
        return (END);
    return (prev);
}

room_t *room(void)
{
    room_t *room = malloc(sizeof(room_t));
    static int id;

    if (!room)
        return (0);
    room->id = id;
    room->busy = 0;
    id++;
    return (room);
}

room_t *ralloc(char *info, int len, char *name, spec_t command)
{
    room_t *new_room;
    static int starts;
    static int ends;

    if ((command == START && starts > 0) || (command == END && ends > 0))
        return (0);
    (command == START) ? starts++, my_printf("##start\n") : 0;
    (command == END) ? ends++, my_printf("##end\n") : 0;
    if (!(new_room = room()))
        return (0);
    new_room->name = name;
    new_room->type = command;
    new_room->x = get_x(info, &len);
    new_room->y = get_y(info, &len);
    if (!(new_room->next = malloc(sizeof(room_t *))))
        return (0);
    new_room->next[0] = 0;
    my_printf("%s %d %d\n", new_room->name, new_room->x, new_room->y);
    return (new_room);
}

room_t *gen_room(char *info, lemin_t *lemin)
{
    static int command;
    char *name;
    room_t *new_room;
    int len = 0;

    command = get_command(info, command);
    if (get_command(info, 0))
        return ((room_t *) 1);
    name = get_name(info, &len);
    for (int i = 0; lemin->anthill[i] != 0; i++) {
        if (!my_strcmp(name, lemin->anthill[i]->name)){
            free(name);
            free(info);
            return (0);
        }
    }
    new_room = ralloc(info, len, name, command);
    free(info);
    command = 0;
    return (new_room);
}

int add_room(char *info, lemin_t *lemin)
{
    room_t *new_room = gen_room(info, lemin);
    room_t **new_anthill = 0;
    int size = 0;

    if (new_room == (room_t *) 1 || !new_room){
        free(info);
        return (!new_room ? -1 : 0);
    }
    for (; lemin->anthill[size] != 0; size++);
    new_anthill = malloc(sizeof(room_t *) * (size + 2));
    if (!new_anthill)
        return (-1);
    for (int i = 0; i < size; i++)
        new_anthill[i] = lemin->anthill[i];
    new_anthill[size]  = new_room;
    new_anthill[size + 1] = 0;
    free(lemin->anthill);
    lemin->anthill = new_anthill;
    return (check_coord(lemin));
}
