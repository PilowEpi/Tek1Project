/*
** EPITECH PROJECT, 2019
** bistromatic.h
** File description:
** my.h files
*/
typedef __builtin_va_list va_list;

#ifndef MY_H
#define MY_H

//my_printf files

typedef struct s_flags
{
    char name;
    void (*fct_ptr)(va_list *);
} t_flags;

void my_print_str(va_list *list);
void my_print_error(va_list *list);
void my_print_char(va_list *list);
void my_print_octal(va_list *list);
void my_print_nbr(va_list *list);
void my_print_unsi_int(va_list *list);
void my_print_ptr(va_list *list);
void my_print_bin(va_list *list);
void my_print_hexa_min(va_list *list);
void my_print_hexa_maj(va_list *list);
void my_print_str_t(va_list *list);
void my_print_percent(va_list *list);
int my_printf(char const *str, ...);


// my_put files

void my_putstr(char const *str);
void my_putchar(char c);
void my_put_octal(unsigned int value);
void my_put_unsi_int(unsigned int nb);
void my_put_nbr(int nb);
void my_put_bin(unsigned int nb);
void my_put_hexa_min(unsigned int nb);
void my_put_hexa_maj(unsigned int nb);
void my_put_hexa_ptr(long int nb);

// lib files

int my_strlen(char const *str);
char *my_stoi(int nb);
int my_size_of_int(int value);
int my_atoi(char const *str);
char *my_strcat(char *dest, char const *src);
int is_op(char c);
char *end_number(char *str);
char *my_strdup(char const *src);
char *my_strcat_m(char const *src1, char const *src2, char *dest);
int is_num(char c);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_strcmp(char const *str1, char const *str2);
int my_getnbr(char const *str);


static const t_flags tab[] = {{'s', &my_print_str},
                            {'i', &my_print_nbr},
                            {'d', &my_print_nbr},
                            {'c', &my_print_char},
                            {'S', &my_print_str_t},
                            {'o', &my_print_octal},
                            {'u', &my_print_unsi_int},
                            {'p', &my_print_ptr},
                            {'b', &my_print_bin},
                            {'x', &my_print_hexa_min},
                            {'X', &my_print_hexa_maj},
                            {'%', &my_print_percent},
                            {'E', &my_print_error}};
#endif /* MY_H */
