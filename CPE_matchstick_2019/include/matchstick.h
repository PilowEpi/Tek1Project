/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef enum run_s {
    RUN,
    END
}run;

typedef enum player_s {
    USER,
    IA
}player;

typedef struct match_s
{
    int max_line;
    int *init_value;
    int *match_value;
}match_t;

typedef struct party_s
{
    match_t game;
    player cur_player;
    run game_state;
    int max_stick;
    int vict_return;
}party_t;

// Verify

int verify_params(char *input);
int verify_line(int line, int max_line);
int verify_matches(int matches, int line, party_t *match);

// Map management

int create_map(match_t *game_value, int line);
void print_map(match_t *game_value);

// USER INPUT

char *get_user_input(void);
int ask_user(party_t *match);

// Lauch a party

int launch_match(party_t *match);

// IA Launch

int ia_play(party_t *match);

// IA Utility

int is_odd(match_t *game);
int get_greater_line(match_t *game);
int get_max_matches(int *match_value, int max_stick, int line);
int total_matches(match_t *game);

int ai_random(int *map, int map_size, int max_m);

#endif /* !MATCHSTICK_H_ */