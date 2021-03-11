/*
** EPITECH PROJECT, 2019
** Lemin
** File description:
** main
*/

#include "my.h"
#include "lemin.h"

int main(int ac, char **av)
{
    if (ac != 1) {
        return (84);
    } else if (start_lemin() == 84) {
        return (84);
    }
    return (0);
}
