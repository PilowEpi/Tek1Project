/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** main
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "my.h"

int main(int ac, char **av)
{
    glo_t gl;

    if (init_globals(&gl) || init_game(&gl))
        return (84);
    if (play_game(&gl))
        return (84);
    clean_memory(&gl);
}
