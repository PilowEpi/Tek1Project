/*
** EPITECH PROJECT, 2020
** need4stek
** File description:
** main file
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "n4s.h"

void debug_answer(simulation_t *sim)
{
    dprintf(2, "Answer :\n");
    dprintf(2, "Status : %u\n", sim->last_answer->status);
    dprintf(2, "info : %f\n", sim->last_answer->info);
    dprintf(2, "time : %lli\n", sim->last_answer->time);
    if (sim->lidar[0] != -1) {
        for (int i = 0; i < 32; i++)
            dprintf(2, "index %d, distance : %f\n", i, sim->lidar[i]);
    }
}

int main(int ac, char **av)
{
    simulation_t *sim = init_simulation();

    if (start_simulation(sim))
        return (84);
    while (1) {
        sleep(2);
        if (get_lidar_information(sim))
            break;
        ia(sim);
        if (sim->status == 20)
            break;
    }
    free(sim->last_answer);
    free(sim);
    return (0);
}
