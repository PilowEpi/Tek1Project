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
void *my_realloc(void *, int);
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
    int fd;
} pf_conf_t;

int my_printf(char const *, ...);
int my_dprintf(int fd, const char *format, ...);

void pf_putchar(char, pf_conf_t *);
void pf_putstr(char const *, pf_conf_t *);
void pf_put_nbr(long long int, pf_conf_t *);
void handle_conf(char, pf_conf_t *, int, int);
void post_conf(char, pf_conf_t *, int, int);

void get_configuration(char const *format, int i, pf_conf_t *conf);
void print_arg(char const *format, int *i, va_list *ap, pf_conf_t *conf);

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
#define is_num(x)     ((x >= '0' && x <= '9') || x == '-')
#define is_print(x)   (x >= 32 && x < 127)

#define to_lowcase(x) (is_lowcase(x) || !is_alpha(x) ? x : x + 'a' - 'A')
#define to_upcase(x)  (is_upcase(x) || !is_alpha(x) ? x : x - 'a' + 'A')


//linked list (lld)

typedef long unsigned int u64;
typedef unsigned int u32;

typedef struct lld
{
    void *data;
    struct lld *next;
    struct lld *prev;
} lld_t;

static lld_t *malloc_list = 0;

lld_t *lld_init_my(void);
void *lld_pop_my(lld_t *lld, int poss);
void lld_insert_my(lld_t *lld, int poss, void *data);
void *my_malloc(u64 size);
void my_free(void *mal);

int lld_db(lld_t *lld);
void lld_free_r(lld_t *lld);
void lld_free(lld_t *lld);
lld_t *lld_init();
void lld_insert_node(lld_t *lld, int poss, lld_t *node);
void lld_insert(lld_t *lld, int pos, void *data);
int lld_len_db(lld_t *lld);
int lld_len(lld_t *lld);
void **lld_lld_to_tab(lld_t *lld);
void *lld_pop_node(lld_t *lld, int pos);
void *lld_pop(lld_t *lld, int pos);
void lld_print_int(lld_t *lld);
void lld_print_str(lld_t *lld);
void *lld_read(lld_t *lld, int poss);
void lld_sort(lld_t *list, int (*cmp)());
void *lld_write(lld_t *lld, int poss, void *data);
lld_t *lld_tab_to_lld(void **tab, int size);

#define IS_FLAG 0x8000000000000000
#define IS_SET(str) ((char *)((u64)str | (u64)0x8000000000000000))
#define K_SPR (127)
#define K_ESC (27)
#define K_ENT (10)
#define K_CTR (1)
#define K_SEP ('[')

int ucp(char *str, char *regex, ...);
char ***ucp_tab(char *str, char *regex, ...);
void ucp_free(char ***tab);
int ucp_varname(char *str);
int ucp_seperator(char *str);
int ucp_arguments(char *str);
int ucp_any(char *str);
int ucp_len(char *str);

void *is_made1(char *str);
void *is_made2(char *str);
void *is_made3(char *str);
void *is_made4(char *str);
void *is_made5(char *str);


#endif
