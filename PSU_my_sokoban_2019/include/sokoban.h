/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

// Usage

int usage_instructions(void);

// Stocking :

// Struct game

typedef struct s_spot {
    int x;
    int y;
    int is_visible;
}spot_t;

typedef struct s_player {
    int x;
    int y;
}player_t;

typedef struct s_game {
    char **map;
    char *reset;
    player_t p;
    int count_spot;
    spot_t *spot_pos;
    int condition;
}game_t;

// map :

int fs_open_file(char const *filepath);
int read_file(char const *filepath);
int open_file(char const *filepath);
char *read_and_stock(int size_buffer, int fd);
int stock_file(int size_buffer, int fd);

// spot :

int stock_spot(game_t *game);
int search_spot(char **map);
int index_of_spot(game_t *game, int x, int y);

// Valide map

int is_invalid_map(char *buffer);

// Game management

int start_game(char *map);
void printw_my_array(char **map);
void find_player(game_t *game);
int restart_game(game_t *game);
int move_player(game_t *game);
void key_pressed(game_t *game, int ch);
void generic_move(game_t *game, int x, int y);

// Winning / Losing condition

int verify_condition(game_t *game);
int losing_condition(game_t *game);
int check_blocked(game_t *game, int y, int x);
int winning_condition(game_t *game);

#endif /* !SOKOBAN_H_ */
