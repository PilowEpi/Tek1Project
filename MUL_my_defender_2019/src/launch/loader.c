/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** prelaunch_game
*/

#include <stdlib.h>
#include "my.h"
#include "defender.h"
#include "struct_defender.h"
#include "dico_defender.h"

void initialize_game(game_t *game, int *returned)
{
    int nb_scene = 0;

    if (*returned == 84)
        return;
    for (; scene_dico[nb_scene].type_scene != LAST; nb_scene++);
    game->def_scene = malloc(sizeof(scene_t) * nb_scene);
    game->nb_scene = nb_scene;
    if (game->def_scene == NULL) {
        *returned = 84;
        return;
    }
    for (int i = 0; i < nb_scene; i++) {
        initialize_scene(&game->def_scene[i], returned,
        scene_dico[i]);
        if (*returned == 84)
            return;
    }
    initialize_defender(game, returned);
}

void init_sound(game_t *game)
{
    game->sound_effect = malloc(sizeof(sfSound *) * 2);
    game->sound_effect[0] = sfSound_create();
    game->sound_effect[1] = sfSound_create();
    game->buffer = malloc(sizeof(sfSoundBuffer *) * 2);
    game->buffer[0] = sfSoundBuffer_createFromFile(archer_s);
    game->buffer[1] = sfSoundBuffer_createFromFile(bomb_s);
    sfSound_setBuffer(game->sound_effect[0], game->buffer[0]);
    sfSound_setBuffer(game->sound_effect[1], game->buffer[1]);
}

int launch_init(void)
{
    int returned = 0;
    window_t win;
    game_t game;

    game.clock = sfClock_create();
    win.type_scene = MENU;
    game.level = NULL;
    game.ambiance = sfMusic_createFromFile(ambiance_s);
    sfMusic_setLoop(game.ambiance, sfTrue);
    init_sound(&game);
    initialize_window(&win, &returned);
    initialize_game(&game, &returned);
    if (returned != 84) {
        play_game(&win, &game);
        destroy_defender(&win, &game);
    }
    return (returned);
}
