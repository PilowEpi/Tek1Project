/*
** EPITECH PROJECT, 2020
** need4stek
** File description:
** init
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "n4s.h"

simulation_t *init_simulation(void)
{
    simulation_t *simulation = malloc(sizeof(simulation_t));

    if (!simulation)
        return (NULL);
    simulation->last_answer = malloc(sizeof(answer_t));
    if (!simulation->last_answer)
        return (NULL);
    simulation->status = 0;
    simulation->lidar[0] = -1;
    simulation->last_answer->status = 0;
    simulation->last_answer->info = 0;
    simulation->last_answer->time = 0;
    return (simulation);
}
