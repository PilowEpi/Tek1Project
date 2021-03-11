/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** my_ia
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "n4s.h"

float calculate_cone(float *lidar, int from, int to)
{
    float result = 0.0;

    for (int i = from; i <= to; i++) {
        result += lidar[i];
        dprintf(2, "cone : %d => %f\n", i, lidar[i]);
    }
    result /= to - from;
    dprintf(2, "result from %d, to %d : %f\n\n\n", from, to, result);
    return (result);
}

int correct_carspeed(simulation_t *sim, float cone)
{
    int tab_cone[] = {2000, 1600, 1300, 800, 400};
    char *tab_speed[] = {"CAR_FORWARD:1\n", "CAR_FORWARD:0.8\n",
        "CAR_FORWARD:0.4\n", "CAR_FORWARD:0.22\n", "CAR_FORWARD:0.15\n"};

    for (int i = 0; i < 5; i++) {
        if (cone >= tab_cone[i]) {
            dprintf(2, "%s\n", exec_command(sim, tab_speed[i]));
            return (1);
        }
    }
    return (0);
}

int choose_dir(simulation_t *sim, int result, char *dir)
{
    size_t size;
    int is_neg = (result < 0) ? 1 : 0;
    char *basic = "WHEELS_DIR:";
    char *info = NULL;

    if (is_neg) {
        my_printf("%s-%s", basic, dir);
    } else {
        my_printf("%s%s", basic, dir);
    }
    getline(&info, &size, stdin);
    return (0);
}

int correct_cardir(simulation_t *sim, float cone_1, float cone_2, float cone_3)
{
    int tab_cone[] = {1200, 900, 600, 300, 220, 120};
    char *tab_dir[] = {"0.005\n", "0.05\n", "0.15\n", "0.25\n",
        "0.4\n", "0.5\n"};
    int result = cone_1 - cone_3;

    for (int i = 0; i < 6; i++) {
        if (cone_2 > tab_cone[i]) {
            choose_dir(sim, result, tab_dir[i]);
            return (1);
        }
    }
    return (0);
}

void ia(simulation_t *sim)
{
    float cone_1 = calculate_cone(sim->lidar, 0, 5);
    float cone_2 = calculate_cone(sim->lidar, 11, 20);
    float cone_3 = calculate_cone(sim->lidar, 27, 31);

    if (cone_1 <= 50 && cone_3 <= 50) {
        exec_command(sim, "CAR_FORWARD:0\n");
        exec_command(sim, "STOP_SIMULATION\n");
    }
    correct_carspeed(sim, cone_2);
    correct_cardir(sim, cone_1, sim->lidar[15], cone_3);
}