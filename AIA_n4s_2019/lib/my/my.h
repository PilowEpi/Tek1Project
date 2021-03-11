/*
** EPITECH PROJECT, 2019
** my_header
** File description:
** Header for all libmy functions
*/

#ifndef _my_h
#define _my_h

// main functions

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *src);
int is_num(char);
void *my_realloc(void *, int, int);
void *my_memcpy(void *, const void *, int);
int get_digit_count(int);
char *my_int_to_str(int);
char *read_file(char *);
char *read_file_desc(int);

//my_printf

#include <stdarg.h>

typedef struct pf_conf{
    int *flags;
    int width;
    int precision;
    int size;
    int char_printed;
} pf_conf_t;

int my_printf(char const *, ...);

void pf_putchar(char, pf_conf_t *);
void pf_putstr(char const *, pf_conf_t *);
void pf_put_nbr(long long int, pf_conf_t *);
void handle_conf(char, pf_conf_t *, int, int);
void post_conf(char, pf_conf_t *, int, int);

void get_configuration(char const *format, int i, pf_conf_t *conf);

void get_flags(char const *format, int i, int fl[]);
int get_size(char const *format, int i);
int get_type(char const *format, int i);
int get_width(char const *format, int i);
int get_precision(char const *format, int i);

int get_flag_index(char const *format, int i);
int get_width_index(char const *format, int i);
int get_precision_index(char const *format, int i);
int get_length_index(char const *format, int i);

int is_numtype(char c);

void my_putnbr_base(unsigned long long int nbr, char const *base, int disp_len,
                    pf_conf_t *conf);
void my_put_unsigned_nbr(unsigned long long int nb, pf_conf_t *conf);
int get_nbr_length(long long int nbr, char *base, int is_signed);
long long int get_number(va_list *, pf_conf_t *, int);

void print_str(va_list *, pf_conf_t *);
void print_str_format(va_list *, pf_conf_t *);
void print_nbr(va_list *, pf_conf_t *);
void print_char(va_list *, pf_conf_t *);
void print_pointer(va_list *, pf_conf_t *);
void print_binary(va_list *, pf_conf_t *);
void print_hexa(va_list *, pf_conf_t *);
void print_unsigned(va_list *, pf_conf_t *);
void print_percent(va_list *, pf_conf_t *);
void print_double(va_list *, pf_conf_t *);
void print_errno(va_list *, pf_conf_t *);
void print_memory(va_list *, pf_conf_t *);
void print_octal(va_list *, pf_conf_t *);
void print_hexa_maj(va_list *, pf_conf_t *);

#define is_numtype(x) (x == '%' || x == 's' || x == 'S' || x == 'c' || x == 'p')

// macros

#define ABS(x)    ((x) < 0 ? -(x) : (x))
#define sign(x)   ((x) < 0 ? -(1) : (1))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))

#define is_lowcase(x) (x >= 'a' && x <= 'z')
#define is_upcase(x)  (x >= 'A' && x <= 'Z')

#define is_alpha(x)   (is_lowcase(x) || is_upcase(x))
#define is_num(x)     (x >= '0' && x <= '9')
#define is_print(x)   (x >= 32 && x < 127)

#define to_lowcase(x) (is_lowcase(x) || !is_alpha(x) ? x : x + 'a' - 'A')
#define to_upcase(x)  (is_upcase(x) || !is_alpha(x) ? x : x - 'a' + 'A')

#endif
