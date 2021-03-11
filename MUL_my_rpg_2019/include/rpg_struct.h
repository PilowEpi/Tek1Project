/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg_struct
*/

#ifndef RPG_STRUCT_H_
#define RPG_STRUCT_H_

#include "rpg.h"

// [ENUM]

typedef enum name_scene_e {
    MENU,
    OPTION,
    PAUSE_MENU,
    END_MENU,
    SKILL_TREE,
    HOW_TO,
    IN_GAME,
    LAST
}t_name_scene;

// [STRUCT]

// GLOBAL STRUCT

typedef struct s_window
{
    sfRenderWindow *window;
    sfVideoMode mode;
    int width;
    int height;
    int frame_limit;
    float scale_ratio;
    sfVector2i mouse_vect;
    sfVector2u win_size;
}window_t;

typedef struct s_clocks
{
    sfClock *clock;
    sfTime Time;
    double seconds;
}clocks_t;

typedef struct s_globals
{
    window_t win;
    t_name_scene curr_scene;
    clocks_t main_clock;
    int nb_scene;
    scene_t *scenes;
    int scale_ratio;
    int is_sound;
    int goal;
    globals_t *data;
    sfTexture *anim_tex;
    sfSprite *anim;
    int pos_x;
    int pos_y;
    long counter;
    sfClock *anim_clock;
} glo_t;

// DRAW STRUCT

typedef struct s_draw_struct
{
    int type_scene;
    int (*draw) (glo_t *gl);
}draw_funct;


#endif /* !RPG_STRUCT_H_ */
