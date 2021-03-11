/*
** EPITECH PROJECT, 2020
** mysh2
** File description:
** header
*/

#ifndef _SH_H
#define _SH_H

#include "my.h"

#define APPEND (0)
#define WRITE  (1)
#define PIPE   (2)
#define READ   (3)
#define DOC    (4)

#define VERSION "42sh v0.1 21-05-2020 (x86_64-linux)"
#define DIR_DEFAULT "$HOME"
#define CONF_DEFAULT "$HOME/.42sh"

#define DOB(i, len, line, chr) \
    (i + 1 < len && line[i] == chr && line[i + 1] == chr)
#define OFF(i, len, line, chr1, chr2) \
    ((DOB(i, len, line, chr1) || DOB(i, len, line, chr2)) ? 1 : 0)
#define CPIPE(type) (type == PIPE || type == DOC)

typedef struct cmd {
    char **commands;
    int *pipes;
    int *connections;
} cmd_t;

typedef struct hist {
    char *cmd;
    char *time;
} hist_t;

typedef struct sh {
    char **original_args;
    char **env;
    lld_t *history;
    lld_t *dirs;
    lld_t *alias;
    lld_t *l_var;
    int streams[2];
    int exit_code;
    int script;
} shell_t;

typedef struct parameter {
    int type;
    cmd_t *cmd;
} par_t;

int shell(shell_t *shell);

int parent(int i, int pid, cmd_t *cmd, char **av);
int child(int i, cmd_t *cmd, shell_t *sh, char **av);
int wait_parent(int pid, shell_t *sh);
void call_execve(char **av, char **envp);
void prepare_child(cmd_t *cmd, int i);

cmd_t *get_parsed_command(char *str, shell_t *sh);
void decrypt_inibited(char **array);
char **my_str_to_word_array(char *src);
int get_connections(int size, char *str, cmd_t *cmd, shell_t *sh);

char *preprocess(char *cmd, shell_t *sh);

int redir_name(char *file);
int ambigu(int type, int *conn);

char *get_filepath(char *name, char *path);
int has_empty_command(cmd_t *cmd);

char **get_paths(char **env);
void try_exec(char *path, char **av, char **envp);

void free_cmd(cmd_t *cmd);
char *substr(char const *str, int a, int b);
int get_next_sep_type(char const *str, int from);
int get_next_sep(char const *str, int from);
char *trim(char *str);

int wrap_setenv(int ac, char **av, shell_t *sh);
int wrap_unsetenv(int ac, char **av, shell_t *sh);
int wrap_env(int ac, char **av, shell_t *env);
int wrap_cd(int ac, char **av, shell_t *sh);
int wrap_exit(int ac, char **av, shell_t *sh);
int wrap_dirs(int ac, char **av, shell_t *sh);
int wrap_pushd(int ac, char **av, shell_t *sh);
int wrap_popd(int ac, char **av, shell_t *sh);
int wrap_set(int ac, char **av, shell_t *sh);
int wrap_unset(int ac, char **av, shell_t *sh);
int wrap_history(int ac, char **av, shell_t *sh);

char *get_env_value(char *name, char *content);
int set_env(shell_t *sh, char *name, char *val);
int unset_env(shell_t *sh, char *name);
int print_env(char **env);
char **set_env_internal(char **env, char *new_value, char *name);

char **create_env(void);
char **dup_env(char **env);
char is_name_set(char **env, char *name);
int get_name_index(char **env, char *name);
char *retrieve_value(char **env, char *name);

int exec_env_from(char **env, char **av, int ac, int from);

int call_builtin(int idx, cmd_t *cmd, shell_t *sh, char **av);
int exec_cd(char *path, shell_t *env);
void free_cd(void);
void init_cd(char **env);

int check_setenv(char **av);
int check_cd(char *path);

int translate_input(char *line);

//script
int main(int ac, char **av, char **env);
void check_script(char **av, char **envp);

//history
int add_history(shell_t *sh, char *cmds);
void show_history(shell_t *sh);

//preprocess
char *get_var_content(char *cmd, int i, shell_t *sh);
char *get_var_length(char *cmd, int i, shell_t *sh);
char *get_var_set(char *cmd, int i, shell_t *sh);
char *get_var_content_at(char *cmd, int i, shell_t *sh);
char *process_star(char *cmd, int i, shell_t *sh);

//star preprocess parsing
char *get_pattern(char *cmd, int i);
char *get_folder(char *cmd, int i);
char *get_append(char *cmd, int i);
int match(char const *s1, char const *s2);
char *merge_dir(char *str_a, char *str_b, char *str_c);

//preprocess utils
int get_varname_index(char *at);
char *check_par(char *str);
char *count_len(char *content);
char *array_in_bounds(char *str, int start, int end);

//getline
int my_getline(char **line, shell_t *sh);
int get_keycode(void);
void complete_str(shell_t *sh, lld_t *str, int *curs);

//dirs
int update_dirs_cwd(shell_t *sh);
char *unpreprocess_dirs_home(shell_t *sh, char *path);
char *preprocess_dirs_home(shell_t *sh, char *path);
lld_t *init_dirs(shell_t *sh);

//loval_var
int print_locale_variable(lld_t *l_var);
char *get_lvar(lld_t *l_var, char *name);
lld_t *locale_variables_init(shell_t *shell);
int set_locale_status(shell_t *sh, int status);
int add_locale_var(char *name, char *inf, lld_t *l_var);
int del_locale_var(char *name, lld_t *l_var);
int sort_l_var(void *obj, void *obj_2);

//cd
int end_cd(shell_t *sh);

//utilities
char *get_cwd(void);
char **read_file_lines(char *file);

//config_file
int load_file_configuration(lld_t *l_var, shell_t *sh);

//alias
lld_t *init_alias(void);

//backstick
char *backstick(char *line, shell_t *sh);
int send_sh(char *line, shell_t *sh);

//ucp
int ucp_arguments(char *str);
int ucp_len(char *str);
int ucp_zero(char *str);
int ucp_argv(char *str);
int ucp_var(char *str);
int ucp_varname(char *str);
int ucp_seperator(char *str);
int ucp_set(char *str);
int ucp_array(char *str);

//dirs
void print_dirs(shell_t *sh, int conf);
int clear_dirs(shell_t *sh);
int get_conf_dirs(int ac, char **av, shell_t *sh);
int dirs_conf(int *conf, char c);
char *get_fullpath(char *path, shell_t *sh);
int move_popd(char *path, shell_t *sh, int conf);
int exec_popd(int info[3], int conf[2], shell_t *sh, char *path);
int pushd_plus(int ac, char **av, shell_t *sh, int conf);
int pushd_dir(int ac, char **av, shell_t *sh, int conf);
int pushd_noarg(shell_t *sh, int conf);
int pushd_owd(shell_t *sh, int conf);
int *get_pushd_info(int ac, char **av, int *info);
int get_conf_pushd(int ac, char **av, shell_t *sh);
int pushd_conf(int *conf, char c);

//local_var
char *get_cwd(void);
char *get_euser(void);
char *get_locale_path_array(shell_t *shell);
char *get_execute_path(shell_t *sh);
char *get_ttyname(void);
char *get_user(void);
char *get_euid(void);
char *get_uid(void);
char *get_gid(void);
char *get_gname(void);
int add_locale_var(char *name, char *inf, lld_t *l_var);
int l_var_add_userinf(lld_t *l_var);
int l_var_add_system(lld_t *l_var);
char *get_lvar(lld_t *l_var, char *name);
char *get_home(shell_t *sh);
int l_var_add_current(lld_t *l_var, shell_t *sh);
void resolve_dir_path(lld_t *l_var, shell_t *sh);
char **copy_array(char **array);
int l_var_add_argv(shell_t *sh, lld_t *l_var);
int init_l_var(lld_t *l_var, shell_t *sh);
int sort_l_var(void *obj, void *obj_2);
int print_locale_variable(lld_t *l_var);
void sort_locale_variable(lld_t *l_var);
lld_t *locale_variables_init(shell_t *shell);
char **read_file_lines(char *file);
int remove_l_var(shell_t *sh, char *name);
int set_locale_status(shell_t *sh, int status);
char **create_info(char *name, char *inf);
int del_locale_var(char *name, lld_t *l_var);
int nb_len(int nb);
char *my_nts(int nb);
void luis_decrypt(char *cmd);

static char *old_pwd = 0;

static char *b_names[] = {"setenv", "unsetenv", "env", "cd", "exit",
    "dirs", "popd", "pushd", "set", "unset", "history", 0
};
static int (*builtins[])(int, char **, shell_t *) = {
    wrap_setenv, wrap_unsetenv, wrap_env, wrap_cd, wrap_exit,
    wrap_dirs, wrap_popd, wrap_pushd, wrap_set, wrap_unset, wrap_history, 0
};

#define CMD_NOT_FOUND ": Command not found\n"
#define NF_OFFSET     20

#define VAR_NOT_AN "setenv: Variable name must contain alphanumeric"\
        " characters.\n"
#define VAR_BEG_LET "setenv: Variable name must begin with a letter.\n"

#define malloc my_malloc
#define free my_free
#define realloc my_realloc

void exit_completion(char *strs, lld_t *posi, lld_t *result, lld_t *str);
int get_arrow(char ch, int *cursor, lld_t *str);
int get_control(char ch, int *cursor, lld_t *str);
int get_function(char ch, int *cursor, lld_t *str);
int retrive_code(char ch, lld_t *str, int *cursor);
int retrive_str(char **line, lld_t *str);
void print_next(int *cursor, lld_t *str, int spaces);
int go_left_cursor(int *cursor, lld_t *str);
int go_rigth_cursor(int *cursor, lld_t *str);
int put_cursor(int *cursor, lld_t *str);
int con_pipe(par_t par, int *i, char *str, shell_t *sh);
#define RES_NEXT ((char *)result->next->data)

#endif
