/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

// Node struct

typedef struct chain_s {
    int nbr;
    struct chain_s *next;
    struct chain_s *prev;
}chain_t;

typedef struct list_s {
    chain_t *head;
    chain_t *end;
    int length;
    int pos_lower;
}list_t;

typedef struct buffer_s {
    char *buffer;
    int index;
}buffer_t;

// Sorting

int start_sort(int ac, char **av);
int get_list_sort(list_t *la, list_t *lb);
int sorting_algo(list_t *la, list_t *lb, buffer_t *buff);

// Checking of sort

int is_sort(list_t *list);
void get_lower(list_t *list);
void rra_search(list_t *la, buffer_t *buff);
void ra_search(list_t *la, buffer_t *buff);

// Sorting move

void rra_move(list_t *la, buffer_t *buff);
void ra_move(list_t *la, buffer_t *buff);
void pb_move(list_t *lb, list_t *la, buffer_t *buff);
void pa_move(list_t *la, list_t *lb, buffer_t *buff);

// Buffer Manage

char *reset_my_buffer(char *buffer, int size_of_buffer);
void print_my_buff(buffer_t *buff);
void add_in_buff(buffer_t *buff, char c);

// Print

void print_list(list_t *list);

#endif /* !PUSHSWAP_H_ */