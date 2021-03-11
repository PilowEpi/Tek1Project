/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
#define TETRIS_H_
#include <stdio.h>
#include <ncurses.h>
#include <dirent.h>
#include <getopt.h>

typedef struct block_t
{
    int error;
    int color;
    int x;
    int y;
    int id;
    char *name;
    char **form;
    int **collision;
    struct block_t *next;
}block_t;

typedef struct map_t
{
    int fix;
    int next_form;
    char **map;
    int x;
    int y;
}map_t;

typedef struct info_t
{
    int is_paused;
    int level;
    int line;
    int score;
    int high_score;
}info_t;

typedef struct scene_t
{
    WINDOW *score;
    WINDOW *tetris;
    WINDOW *next_form;
}scene_t;

typedef struct s_options {
    int map_size_x;
    int map_size_y;
    int size;
    int start_level;
    int key_left;
    int key_right;
    int key_turn;
    int key_drop;
    int key_quit;
    int key_pause;
    int without_next;
    int debug_mode;
}options_t;

typedef struct info_actual_s
{
    int x;
    int y;
}info_actual_tetris_t;

typedef struct game_t
{
    info_actual_tetris_t info;
    scene_t scene;
    block_t *block;
    options_t data;
    map_t map;
    info_t tetris_info;
    char **tetriminos;
    int frame;
}game_t;

typedef struct s_get_option {
    char name;
    int (*fct_opt)(char *args, options_t *data);
}get_option_t;

// [TETRIS FUNCTION]

int display_help(char *args, options_t *data);
int get_option(int ac, char **av, options_t *data);
int set_key_right(char *argvs, options_t *data);
int set_key_left(char *argvs, options_t *data);
int set_key_drop(char *argvs, options_t *data);
int set_key_turns(char *argvs, options_t *data);
int check_data(options_t *data);
void init_data(options_t *data);
int set_key_quit(char *argvs, options_t *data);
int set_key_pause(char *argvs, options_t *data);
int set_level(char *argvs, options_t *data);
int set_debug(char *argvs, options_t *data);
int set_without(char *argvs, options_t *data);
int set_mapsize(char *argvs, options_t *data);
int start_debug_mode(options_t *data, game_t *game);
int set_error(char *argvs, options_t *data);
game_t *init_game(void);
int check_files(char *s);
int init_list(game_t *game);
int strcpy_cat(char *files, char *s, block_t **head, game_t *game);
block_t *new_block(char *s);
char *read_file(int fd, char *s);
int fill_struct(block_t *block, char *line);
void push_node(block_t **head, block_t *block);
int games_ncurses(game_t *game);
int draw_tetris(void);
void sort_list(game_t *game);
void drawt(int color, int x, int y);
void drawe(int color, int x, int y);
void drawr(int color, int x, int y);
void drawi(int color, int x, int y);
void draws(int color, int x, int y);
int play_tetris(game_t *game);
void init_score(game_t *game);
void init_nextform(game_t *game);
void init_tetris_game(game_t *game);
void fill_list(char **tab, block_t **head);
char **sort_files(char **tab);
void draw_next_form(block_t *next_form, game_t *game);
void draw_actual_form(game_t *game, block_t *actual);
int print_clock(game_t *game);
int refresh_game(game_t *game);
void print_score(game_t *game);
void draw_game(game_t *game);
void draw_actual_form(game_t *game, block_t *actual);
void sorted_list(game_t *game, DIR *fd, block_t **head, int a);
int check_nb_line(char *line, block_t *block);
int check_nb_cols(char *line, block_t *block);
void get_time(game_t *game, int *second, int *minute);
void fill_tab(int i, int *e, block_t *block, int j);
int collision_or_not(game_t *game, block_t *tmp);
int verify_line(game_t *game);
// [TETRIS KEY FUNCTION]

int choose_key(game_t *game, int key, block_t *tmp);
int quit_key(game_t *game, block_t *tmp);
int drop_key(game_t *game, block_t *tmp);
int pause_key(game_t *game, block_t *tmp);
int left_key(game_t *game, block_t *tmp);
int right_key(game_t *game, block_t *tmp);
int turn_key(game_t *game, block_t *tmp);

static const get_option_t opt[] =
{
    {2, &display_help},
    {'l', &set_key_left},
    {'r', &set_key_right},
    {'t', &set_key_turns},
    {'d', &set_key_drop},
    {'L', &set_level},
    {'q', &set_key_quit},
    {'p', &set_key_pause},
    {3, &set_mapsize},
    {'w', &set_without},
    {'D', &set_debug},
    {'?', &set_error}
};

#endif /* !TETRIS_H_ */