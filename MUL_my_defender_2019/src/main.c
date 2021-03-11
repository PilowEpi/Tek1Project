/*
** EPITECH PROJECT, 2020
** Test_tower_defence
** File description:
** main defender
*/

#include <stdlib.h>
#include <stddef.h>
#include "my.h"
#include "defender.h"

int print_usage(void)
{
    my_printf("USAGE\n");
    my_printf("   ./my_defender \n\n\n");
    my_printf("OPTIONS\n");
    my_printf(" -h\tprint the usage and quit.\n\n");
    return (0);
}

int main(int ac, char **av)
{
    srand(av);
    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        return (print_usage());
    } else if (ac <= 2) {
        if (ac == 1)
            return (launch_init());
        else if (ac == 2)
            return (launch_init());
    } else {
        my_printf("Invalid syntax : try with the -h for help\n");
        return (84);
    }
    return (0);
}
