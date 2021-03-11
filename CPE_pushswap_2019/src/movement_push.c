/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** movement_push
*/
#include "pushswap.h"
#include <stddef.h>
#include <unistd.h>

void rra_move(list_t *la, buffer_t *buff)
{
    chain_t *tmp = la->end->prev;

    la->end->next = la->head;
    la->end->prev->next = NULL;
    la->end->prev = NULL;
    la->head->prev = la->end;
    la->head = la->end;
    la->end = tmp;
    add_in_buff(buff, 'r');
    add_in_buff(buff, 'r');
    add_in_buff(buff, 'a');
}

void ra_move(list_t *la, buffer_t *buff)
{
    chain_t *tmp = la->end;

    la->head = la->head->next;
    la->end->next = la->head->prev;
    la->end = la->end->next;
    la->head->prev = NULL;
    la->end->prev = tmp;
    la->end->next = NULL;
    add_in_buff(buff, 'r');
    add_in_buff(buff, 'a');
}

void pa_move(list_t *la, list_t *lb, buffer_t *buff)
{
    chain_t *tmp = la->head;

    la->head = lb->head;
    lb->head = lb->head->next;
    if (lb->head != NULL)
        lb->head->prev = NULL;
    if (la->head == NULL) {
        la->head->next = NULL;
        la->end = la->head;
    } else {
        la->head->next = tmp;
    }
    lb->length--;
    la->length++;
    add_in_buff(buff, 'p');
    add_in_buff(buff, 'a');
}

void pb_move(list_t *lb, list_t *la, buffer_t *buff)
{
    chain_t *tmp = lb->head;

    lb->head = la->head;
    la->head = la->head->next;
    if (la->head != NULL)
        la->head->prev = NULL;
    if (lb->head == NULL) {
        lb->head->next = NULL;
        lb->end = lb->head;
    } else {
        lb->head->next = tmp;
    }
    lb->length++;
    la->length--;
    add_in_buff(buff, 'p');
    add_in_buff(buff, 'b');
}