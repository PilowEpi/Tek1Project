/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** dico_defender
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "struct_defender.h"
#include "defender.h"
#include "path_defender.h"

#ifndef DICO_DEFENDER_H_
#define DICO_DEFENDER_H_


// How Create or Move a Data :

/*
** init_sprite_t
** {Path_sprite, x, y};
*/

/*
** init_but_t
** {Path_sprite, x, y, function_pointer, rect.heigth, rect.width,
    [Table of iddle, table of over, table of clicked]};
**
*/

// MENU DATA

static const init_sprite_t menu_s[] =
{
    {plains_background, 0, 0},
    {menu_logo_sprite, 485, 200},
    {0, 0, 0}
};

static const init_but_t menu_b[] =
{
    {menu_button_play, 800, 600, &swap_to_levels, 330, 330,
        {{0, 0, 334, 330}, {335, 0, 334, 330}, {670, 0, 334, 330}}},
    {menu_button_quit, 1150, 600, &close_window, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {menu_button_option, 600, 600, &swap_to_option, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

// OPTION DATA

static const init_sprite_t option_s[] =
{
    {plains_background, 0, 0},
    {option_plate, 485, 200},
    {0, 0, 0}
};

static const init_but_t option_b[] =
{
    {menu_button_quit, 1150, 600, &swap_to_menu, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {menu_button_left, 600, 400, &swap_small_size, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {menu_button_right, 800, 400, &swap_big_size, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

static const init_text_t option_t[] =
{
    {"Size", text_font, 140, 550, 250, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// LEVELS DATA

static const init_sprite_t levels_s[] =
{
    {plains_background, 0, 0},
    {desert_background, 0, 0},
    {ice_background, 0, 0},
    {volcano_background, 0, 0},
    {option_plate, 485, 200},
    {0, 0, 0}
};

static const init_but_t levels_b[] =
{
    {menu_button_left, 1000, 400, &touch_sub, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {level_one, 1020, 600, &swap_to_in_game, 100, 100,
        {{0, 0, 100, 100}, {100, 0, 100, 100}, {200, 0, 100, 100}}},
    {level_two, 1120, 600, &swap_to_in_game, 100, 100,
        {{0, 0, 100, 100}, {100, 0, 100, 100}, {200, 0, 100, 100}}},
    {level_three, 1220, 600, &swap_to_in_game, 100, 100,
        {{0, 0, 100, 100}, {100, 0, 100, 100}, {200, 0, 100, 100}}},
    {menu_button_right, 1200, 400, &touch_add, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {menu_button_right, 880, 725, &swap_to_menu, 175, 175,
        {{0, 0, 175, 175}, {175, 0, 175, 175}, {350, 0, 175, 175}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

static const init_text_t levels_t[] =
{
    {"Forest", text_font, 150, 750, 225, 255, 221, 116},
    {"Desert", text_font, 150, 750, 225, 255, 193, 154},
    {"Ice", text_font, 150, 750, 225, 255, 255, 255},
    {"Volcano", text_font, 150, 750, 225, 255, 216, 41},
    {"World Type:", text_font, 80, 580, 415, 255, 255, 255},
    {"Difficulty:", text_font, 80, 600, 600, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// GAME DATA

static const init_sprite_t game_s[] =
{
    {left_hud, 0, 0},
    {top_hud, 200, 0},
    {minimap_hud, 1613, -15},
    {0, 0, 0}
};

static const init_but_t game_b[] =
{
    {level_up_tower, 30, 300, &levelup, 100, 100,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {sell_tower, 30, 500, &sell, 100, 100,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {tower_1_hud, 30, 200, &place_tower, 85, 85,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {tower_2_hud, 30, 375, &place_tower, 85, 85,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {tower_3_hud, 30, 550, &place_tower, 85, 85,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {tower_4_hud, 30, 725, &place_tower, 85, 85,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

static const init_text_t game_txt[] =
{
    {"Gold", text_font, 55, 10, 10, 255, 255, 255},
    {"0", text_font, 50, 35, 60, 255, 255, 255},
    {"Wave", text_font, 50, 210, 10, 255, 255, 255},
    {"0", text_font, 50, 385, 10, 255, 255, 255},
    {"Score", text_font, 50, 585, 10, 255, 255, 255},
    {"0", text_font, 50, 785, 10, 255, 255, 255},
    {"Vie", text_font, 50, 1385, 10, 255, 255, 255},
    {"0", text_font, 50, 1485, 10, 255, 255, 255},
    {"Prix : 100", text_font, 40, 10, 900, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};


// PAUSE DATA

static const init_sprite_t pause_s[] =
{
    {plains_background, 0, 0},
    {option_plate, 485, 200},
    {0, 0, 0}
};


static const init_but_t pause_b[] =
{
    {menu_return, 1050, 500, &swap_to_menu, 175, 175,
        {{0, 0, 175, 175}, {0, 0, 175, 175}, {0, 0, 175, 175}}},
    {button_reset, 720, 500, &swap_to_in_game, 175, 175,
        {{0, 0, 175, 175}, {0, 0, 175, 175}, {0, 0, 175, 175}}},
    {sell_tower, 485, 200, &close_window, 100, 100,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

static const init_text_t pause_t[] =
{
    {"PAUSE", text_font, 150, 820, 300, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};


// END DATA

static const init_sprite_t end_s[] =
{
    {option_plate, 485, 200},
    {0, 0, 0}
};


static const init_but_t end_b[] =
{
    {menu_return, 1050, 500, &swap_to_menu, 175, 175,
        {{0, 0, 175, 175}, {0, 0, 175, 175}, {0, 0, 175, 175}}},
    {button_reset, 720, 500, &swap_to_in_game, 175, 175,
        {{0, 0, 175, 175}, {0, 0, 175, 175}, {0, 0, 175, 175}}},
    {sell_tower, 485, 200, &close_window, 100, 100,
        {{0, 0, 85, 85}, {0, 0, 85, 85}, {0, 0, 85, 85}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

static const init_text_t end_t[] =
{
    {"YOU LOSE", text_font, 150, 820, 300, 255, 255, 255},
    {"YOU WIN", text_font, 150, 820, 300, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};
// GLOBAL DATA

static const init_scene scene_dico[] =
{
    {MENU, menu_b, menu_s, NULL},
    {OPTION, option_b, option_s, option_t},
    {LEVELS, levels_b, levels_s, levels_t},
    {IN_GAME, game_b, game_s, game_txt},
    {PAUSE, pause_b, pause_s, pause_t},
    {END_GAME, end_b, end_s, end_t},
    {LAST, 0, 0, 0}
};

static const draw_t draw_tab[] =
{
    {MENU, &start_menu},
    {OPTION, &start_option},
    {LEVELS, &start_levels},
    {IN_GAME, &start_defender},
    {PAUSE, &start_pause},
    {END_GAME, &start_end},
    {LAST, NULL}
};

static const hud_stat_t hud[] =
{
    {TOWER_CELL, 0, 2},
    {CASTLE_CELL, 0, 0},
    {EMPTY_CELL, 0, 4},
    {PORTAL_CELL, 0, 0},
    {NOT_A_CELL, 0, 0}
};

static const spritesheet_info_t tower_ss_info[] =
{
    {ARCHER, 90, 10, 0, 2},
    {BOMB, 90, 10, 0, 2},
    {MAGIC, 100, 10, 0, 2},
    {SLOW, 100, 10, 0, 2}
};

static const spritesheet_info_t enemy_ss_walk[] =
{
    {MARVIN, 55, 1, 18, 0.4},
    {GOLEM, 58, 0, 19, 0.4},
    {ORC, 63, 0, 8, 0.4},
    {THIEF, 54, 0, 9, 0.4},
    {BAT, 57, 0, 9, 0.2},
    {YETI, 66, 0, 9, 0.4},
    {TRUMP, 90, 0, 18, 2}
};

static const spritesheet_info_t enemy_ss_die[] =
{
    {MARVIN, 56, 3, 20, 2},
    {GOLEM, 58, 0, 19, 2},
    {ORC, 0, 0, 0, 2},
    {THIEF, 0, 0, 0, 2},
    {BAT, 0, 0, 0, 2},
    {YETI, 0, 0, 0, 2},
    {TRUMP, 0, 0, 0, 2}
};

static const spritesheet_info_t enemy_ss_attack[] =
{
    {MARVIN, 55, 0, 20, 2},
    {GOLEM, 58, 0, 13, 2},
    {ORC, 0, 0, 0, 0.4},
    {THIEF, 0, 0, 0, 0.4},
    {BAT, 0, 0, 0, 0.4},
    {YETI, 0, 0, 0, 0.4},
    {TRUMP, 0, 0, 0, 0.4}
};

#endif /* !DICO_DEFENDER_H_ */
