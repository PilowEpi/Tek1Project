/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg_dico
*/

#ifndef RPG_DICO_H_
#define RPG_DICO_H_

#include "lib_csfml.h"
#include "rpg_dico.h"
#include "rpg_path.h"

// [SCENE DICO]

// Menu

static const init_sprite_t menu_s[] =
{
    {main_background, 0, 0},
    {main_logo, 400, 200},
    {0, 0, 0}
};

static const init_but_t menu_b [] =
{
    {menu_button, 680, 600, &swap_to_play, 120, 600,
        {{0, 0, 600, 120}, {0, 145, 600, 120}, {0, 290, 600, 120}}},
    {menu_button, 680, 750, &swap_to_option, 120, 600,
        {{650, 0, 600, 120}, {650, 145, 600, 120}, {650, 290, 600, 120}}},
    {menu_button, 680, 900, &close_window, 120, 600,
        {{1310, 0, 600, 120}, {1310, 145, 600, 120}, {1310, 290, 600, 120}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

// Option

static const init_sprite_t option_s [] =
{
    {main_background, 0, 0},
    {0, 0, 0}
};

static const init_but_t option_b [] =
{
    {menu_button, 680, 600, &swap_to_tuto, 120, 600,
        {{0, 450, 600, 120}, {0, 595, 600, 120}, {0, 740, 600, 120}}},
    {menu_button, 750, 400, &turn_on_sound, 150, 150,
        {{650, 450, 150, 150}, {650, 600, 150, 150}, {650, 750, 150, 150}}},
    {menu_button, 900, 400, &mute_sound, 150, 150,
        {{800, 450, 150, 150}, {800, 600, 150, 150}, {800, 750, 150, 150}}},
    {menu_button, 1050, 400, &swap_to_menu, 150, 150,
        {{950, 450, 150, 150}, {950, 600, 150, 150}, {950, 750, 150, 150}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

// PAUSE_MENU

static const init_sprite_t pause_s [] =
{
    {main_background, 0, 0},
    {0, 0, 0}
};

static const init_text_t pause_t [] =
{
    {"PAUSE", main_font, 150, 800, 300, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

static const init_but_t pause_b [] =
{
    {menu_button, 660, 700, &close_window, 120, 600,
        {{1310, 0, 600, 120}, {1310, 145, 600, 120}, {1310, 290, 600, 120}}},
    {menu_button, 980, 550, &swap_to_play, 150, 150,
        {{950, 450, 150, 150}, {950, 600, 150, 150}, {950, 750, 150, 150}}},
    {menu_button, 780, 550, &swap_to_menu, 150, 150,
        {{1150, 450, 150, 150}, {1150, 600, 150, 150}, {1150, 750, 150, 150}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

// END_GAME

static const init_sprite_t end_s [] =
{
    {main_background, 0, 0},
    {0, 0, 0}
};

static const init_text_t end_t [] =
{
    {"YOU WIN !", main_font, 150, 700, 300, 255, 255, 255},
    {"YOU LOSE !", main_font, 150, 680, 300, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

static const init_but_t end_b [] =
{
    {menu_button, 660, 700, &close_window, 120, 600,
        {{1310, 0, 600, 120}, {1310, 145, 600, 120}, {1310, 290, 600, 120}}},
    {menu_button, 980, 550, &swap_to_menu, 150, 150,
        {{950, 450, 150, 150}, {950, 600, 150, 150}, {950, 750, 150, 150}}},
    {menu_button, 780, 550, &swap_to_menu, 150, 150,
        {{1150, 450, 150, 150}, {1150, 600, 150, 150}, {1150, 750, 150, 150}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

// Skill Tree

static const init_text_t skill_t [] =
{
    {"SKILL TREE", main_font, 150, 680, 50, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

static const init_sprite_t skill_s [] =
{
    {main_background, 0, 0},
    {0, 0, 0}
};

static const init_but_t skill_b [] =
{
    {skill_background, 700, 250, &more_dmg, 150, 150,
        {{0, 0, 145, 145}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 700, 550, &more_healh, 150, 150,
        {{0, 0, 145, 145}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 700, 850, &more_speed, 150, 150,
        {{0, 0, 145, 145}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 1100, 250, &more_ligth, 150, 150,
        {{0, 0, 145, 145}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 1100, 550, &more_armor, 150, 150,
        {{0, 0, 145, 145}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 1100, 850, &get_pistol, 150, 150,
        {{0, 0, 145, 145}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 700, 250, NULL, 0, 0,
        {{150, 0, 145, 145}, {150, 148, 148, 150}, {150, 300, 148, 150}}},
    {skill_background, 700, 540, NULL, 0, 0,
        {{150, 148, 148, 150}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 700, 830, NULL, 0, 0,
        {{150, 300, 148, 150}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 1110, 240, NULL, 0, 0,
        {{300, 0, 145, 145}, {150, 148, 148, 150}, {150, 300, 148, 150}}},
    {skill_background, 1105, 540, NULL, 0, 0,
        {{300, 148, 148, 150}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {skill_background, 1100, 830, NULL, 0, 0,
        {{300, 300, 148, 150}, {0, 148, 148, 150}, {0, 300, 148, 150}}},
    {menu_button, 880, 900, &swap_to_play, 150, 150,
        {{950, 450, 150, 150}, {950, 600, 150, 150}, {950, 750, 150, 150}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

// HOW TO PLAY

static const init_but_t tuto_b [] =
{
    {menu_button, 880, 900, &swap_to_option, 150, 150,
        {{950, 450, 150, 150}, {950, 600, 150, 150}, {950, 750, 150, 150}}},
    {0, 0, 0, 0, 0, 0, {{0}}}
};

static const init_sprite_t tuto_s [] =
{
    {main_background, 0, 0},
    {0, 0, 0}
};

static const init_text_t tuto_t [] =
{
    {"HOW TO PLAY", main_font, 150, 650, 50, 255, 255, 255},
    {"=> A = Ramasser", main_font, 70, 400, 300, 255, 255, 255},
    {"=> Z = Avancer", main_font, 70, 400, 400, 255, 255, 255},
    {"=> Space = attaquer", main_font, 70, 400, 500, 255, 255, 255},
    {"=> 0-9 = utiliser Item", main_font, 70, 400, 600, 255, 255, 255},
    {"=> S = Skill Tree", main_font, 70, 400, 700, 255, 255, 255},
    {"=> Echap = Pause", main_font, 70, 400, 800, 255, 255, 255},
    {0, 0, 0, 0, 0, 0, 0, 0}
};


// [GLOBAL DICO]

static const init_scene data_scene [] =
{
    {MENU, menu_b, menu_s, 0, 0},
    {OPTION, option_b, option_s, 0, 0},
    {PAUSE_MENU,  pause_b, pause_s, pause_t, 0},
    {END_MENU, end_b, end_s, end_t, 0},
    {SKILL_TREE, skill_b, skill_s, skill_t, 0},
    {HOW_TO, tuto_b, tuto_s, tuto_t, 0},
    {LAST, 0, 0, 0, 0}
};

static const draw_funct draw_s [] =
{
    {MENU, &draw_menu},
    {OPTION, &draw_option},
    {PAUSE_MENU, &draw_pause},
    {END_MENU, &draw_end},
    {SKILL_TREE, &draw_skill},
    {HOW_TO, &draw_tuto},
    {IN_GAME, &draw_game},
    {LAST, 0}
};

#endif /* !RPG_DICO_H_ */
