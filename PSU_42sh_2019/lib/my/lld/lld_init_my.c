/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** hello
*/

#include "../my.h"
#include <stdlib.h>

lld_t *lld_init_my(void)
{
    lld_t *lld = malloc(sizeof(lld_t));

    if (!lld)
        exit(84);
    lld->next = 0;
    lld->prev = 0;
    lld->data = 0;
    return (lld);
}
