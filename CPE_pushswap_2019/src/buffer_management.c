/*
** EPITECH PROJECT, 2019
** CPE_pushswap_2019
** File description:
** buffer_management
*/

#include <unistd.h>
#include "pushswap.h"

char *reset_my_buffer(char *buffer, int size_of_buffer)
{
    int i = 0;

    while (i < size_of_buffer) {
        buffer[i] = '\0';
        i++;
    }
    return (buffer);
}

void print_my_buff(buffer_t *buff)
{
    write(1, buff->buffer, sizeof(char) * buff->index);
    buff->buffer = reset_my_buffer(buff->buffer, buff->index);
    buff->index = 0;
}

void add_in_buff(buffer_t *buff, char c)
{
    buff->buffer[buff->index] = c;
    buff->index++;
    if (buff->index == 50000000) {
        print_my_buff(buff);
    }
}