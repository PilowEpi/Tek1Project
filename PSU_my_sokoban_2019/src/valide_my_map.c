/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** valide_my_map
*/

#include <stddef.h>
#include <stdlib.h>

int *count_char(char *buffer, int *count)
{
    for (int i = 0; buffer[i] != 0; i++) {
        switch (buffer[i]) {
            case 'O':
                count[0]++;
                break;
            case 'X':
                count[1]++;
                break;
            case '#':
            case ' ':
            case '\n':
                break;
            case 'P':
                count[2]++;
                break;
            default :
                return (NULL);
        }
    }
    return (count);
}

int check_count(int *count)
{
    if (count[0] == 0 || count[1] == 0 || count[2] == 0)
        return (84);
    if (count[0] != count[1])
        return (84);
    else if (count[2] != 1)
        return (84);
    return (0);
}

int is_invalid_map(char *buffer)
{
    int *count = malloc(sizeof(int) * 3);

    if (count == NULL)
        return (84);
    count[0] = 0;
    count[1] = 0;
    count[2] = 0;
    count = count_char(buffer, count);

    if (count == NULL)
        return (84);
    else if (check_count(count) == 84)
        return (84);
    free(count);
    return (0);
}