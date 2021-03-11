/*
** EPITECH PROJECT, 2020
** need4stek
** File description:
** lidar handling
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "n4s.h"

void print_lidar(simulation_t *sim)
{
    dprintf(2, "Lidar information :\n");
    for (int i = 0; i < 32; i++) {
        dprintf(2, "%f\n", sim->lidar[i]);
    }
}

int set_lidar_information(simulation_t *sim, char *result, int index)
{
    for (int i = 0; i < 32; i++) {
        sim->lidar[i] = atof(result + index);
        for (index; result[index] != ':'; index++);
        index++;
    }
    free(result);
    return (0);
}

int get_lidar_information(simulation_t *sim)
{
    char *result;
    int count = 0;

    result = exec_command(sim, "GET_INFO_LIDAR\n");
    if (!result || sim->last_answer->status != 1)
        return (84);
    for (int i = 0; result[i]; i++) {
        if (result[i] == ':')
            count++;
        if (count == 3) {
            count = i + 1;
            break;
        }
    }
    return (set_lidar_information(sim, result, count));
}