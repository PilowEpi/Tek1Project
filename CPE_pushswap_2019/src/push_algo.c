/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** push_algo
*/

#include "my.h"
#include "pushswap.h"
#include <stddef.h>
#include <unistd.h>

void rra_search(list_t *la, buffer_t *buff)
{
    int pos = 0;

    pos = la->length - la->pos_lower;
    while (pos != 0 && la->length > 1) {
        rra_move(la, buff);
        add_in_buff(buff, ' ');
        pos--;
    }
}

void ra_search(list_t *la, buffer_t *buff)
{
    int pos = 0;

    pos = la->pos_lower;
    while (pos != 0 && la->length > 1) {
        ra_move(la, buff);
        add_in_buff(buff, ' ');
        pos--;
    }
}

void selec_algo(list_t *la, list_t *lb, buffer_t *buff)
{
    while (la->length > 0) {
        get_lower(la);
        if (la->length / 2 > la->pos_lower)
            ra_search(la, buff);
        else
            rra_search(la, buff);
        pb_move(lb, la, buff);
        add_in_buff(buff, ' ');
    }
    while (lb->length != 0) {
        pa_move(la, lb, buff);
        if (lb->length >= 1)
            add_in_buff(buff, ' ');
    }
}

int sorting_algo(list_t *la, list_t *lb, buffer_t *buff)
{
    if (is_sort(la) != 0) {
        selec_algo(la, lb, buff);
        print_my_buff(buff);
    }
    write(1, "\n", 1);
    return (0);
}