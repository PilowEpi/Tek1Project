/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

//[ ASM ]

typedef struct file_s
{
    int line;
    char *command;
    char **args;
    int size;
    char byte_code[30];
    struct file_s *next;
    struct file_s *prev;
}file_t;

typedef struct asm_s
{
    char *name;
    char **base_file;
    file_t *command;
    int prog_size;
}asm_t;

// Launch

int launch_asm(char *filename);
int get_data_from_file(asm_t *asm_data, char *filename);
char **open_file(char *path_file);
char *read_file(int fd_file);
int length_of_file(int fd_file);
int fs_open_file(char const *filepath);
int verify_constant(void);
void clean_memory(asm_t *asm_data);

// Parsing

char *get_name(char *filename);
int parse_data(asm_t *asm_data);
int set_data(asm_t *asm_data);
int add_line_to_command(asm_t *asm_data, int line, int *line_counter);
int fill_command_table(file_t *file, char *line);
void debug_task(file_t *task);
file_t *add_node(file_t **head, int *line_counter);
int complete_two_node(char *lab, char *cmd, asm_t *asm_data, int *line_counter);

// Writing

int create_comp_file(asm_t *asm_data);
int write_in_file(asm_t *asm_data, int fd);

// Verifier

int verify_data(asm_t *asm_data);
int get_type(char *str);
int verify_syntax(file_t *curr);
void print_line_error(int line);
int verify_name_place(file_t *head);
int verify_args(file_t *curr);
int is_correct_args(file_t *curr, int op);
int verify_comment(file_t *head);

// Identifier

int is_reg(char *str);
int is_label(char *str);
int is_indirect(char *str);
int is_direct(char *str);
int is_label_char(char c);
int is_index(char *str);

// Code

int byte_sums(asm_t *asm_data);
int get_command_id(char *str);
int calculate_params(file_t *curr, int *ptr);
int calculate_function(file_t *curr, int *ptr);
int write_byte_code(int fd, asm_t *asm_data);
int calculate_args(file_t *curr, int *ptr);
int write_register(char *str, file_t *curr, int *ptr);
int write_direct(char *str, file_t *curr, int *ptr);
int write_indirect(char *str, file_t *curr, int *ptr);
int write_index(char *str, file_t *curr, int *ptr);

// Base conversion

char *my_convert(int nb, int base, int lowercase);

#endif /* !COREWAR_H_ */