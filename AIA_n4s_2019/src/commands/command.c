/*
** EPITECH PROJECT, 2020
** need4stek
** File description:
** command handling
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "n4s.h"

void get_information(simulation_t *sim, char *result)
{
    dprintf(2, "%s", result);
}

void get_simtime(simulation_t *sim, char *result)
{

}

void translate_answer(simulation_t *sim, char *result)
{
    int lenght = 0;

    if (!result)
        return;
    sim->last_answer->status = (unsigned char) my_getnbr(result);
}

char *exec_command(simulation_t *sim, char *command)
{
    char *result = NULL;
    size_t size;

    my_printf(command);
    getline(&result, &size, stdin);
    translate_answer(sim, result);
    return (result);
}