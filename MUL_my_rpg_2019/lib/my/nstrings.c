/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** n strings util
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len = 0;
    int i = 0;

    for (; dest[len] != '\0'; len++);
    for (; src[i] != '\0' && i < nb; i++)
        dest[len + i] = src[i];
    if (i == nb)
        dest[len + i] = '\0';
    return (dest);
}

int my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++){
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

char *my_strncpy(char *dest, char const *str, int n)
{
    int i;
    int len = 0;

    for (len = 0; str[len] != '\0'; len++);
    for (i = 0; i < n && i < len; i++)
        dest[i] = str[i];
    if (n > len)
        dest[i] = '\0';
    return dest;
}

static int get_index_strstr(char *str, char const *to_find)
{
    int first_occur_i = my_strlen(str) + 1;
    int to_find_i = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == to_find[to_find_i]){
            first_occur_i = i - to_find_i;
            to_find_i++;
        }else{
            first_occur_i = my_strlen(str) + 1;
            to_find_i = 0;
            if (str[i] == to_find[to_find_i]){
                first_occur_i = i - to_find_i;
                to_find_i++;
            }
        }
        if (to_find[to_find_i] == '\0')
            break;
    }
    return (first_occur_i);
}

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(str);
    int index = get_index_strstr(str, to_find);
    char copy[len + 1];

    if (index > len)
        return (0);
    return (str + index);
}
