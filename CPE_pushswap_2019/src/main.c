/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** main
*/

#include "my.h"
#include "pushswap.h"

void write_usage(void)
{
    my_printf("USAGE\n");
    my_printf("     ./push_swap [list_of_number]\n");
    my_printf("DESCRIPTION\n");
    my_printf("     [list_of_number] is a list of 'n' number that gonna\n");
    my_printf("      be sort with minimum number of tasks\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        write_usage();
        return (0);
    }
    start_sort(ac, av);
    return (0);
}