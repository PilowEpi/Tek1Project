/*
** EPITECH PROJECT, 2020
** need4stek
** File description:
** launch
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "n4s.h"

int set_maxspeed(simulation_t *sim)
{
    char *result;
    int count = 0;

    result = exec_command(sim, "GET_CAR_SPEED_MAX\n");
    if (!result)
        return (1);
    for (int i = 0; result[i]; i++) {
        if (result[i] == ':')
            count++;
        if (count == 3) {
            count = i + 1;
            break;
        }
    }
    dprintf(2, "%s\n", result);
    sim->max_speed = atof(result + count);
    free(result);
    return (0);
}

int set_minspeed(simulation_t *sim)
{
    char *result;
    int count = 0;

    result = exec_command(sim, "GET_CAR_SPEED_MIN\n");
    if (!result)
        return (1);
    for (int i = 0; result[i]; i++) {
        if (result[i] == ':')
            count++;
        if (count == 3) {
            count = i + 1;
            break;
        }
    }
    dprintf(2, "%s\n", result);
    sim->min_speed = atof(result + count);
    free(result);
    return (0);
}

int set_carspeed(simulation_t *sim)
{
    if (set_maxspeed(sim))
        return (1);
    if (set_minspeed(sim))
        return (1);
    return (0);
}

int start_simulation(simulation_t *sim)
{
    char *result;

    result = exec_command(sim, "START_SIMULATION\n");
    if (!result || sim->last_answer->status != 1)
        return (84);
    free(result);
    if (set_carspeed(sim))
        return (84);
    debug_answer(sim);
    return (0);
}