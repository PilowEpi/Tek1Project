/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** event_option
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "struct_defender.h"
#include "defender.h"
#include "my.h"
#include "dico_defender.h"

void defender_mouse_over(window_t *win, game_t *game)
{
    win->mouse_vect = sfMouse_getPositionRenderWindow(win->window);
    for (int i = 0; i < game->def_scene[IN_GAME].nb_button; i++) {
        if (sfFloatRect_contains(&(game->def_scene[IN_GAME].
            button[i].rect), win->mouse_vect.x, win->mouse_vect.y))
            sfSprite_setTextureRect(game->def_scene[IN_GAME].
                button[i].b_sprite.img, game->def_scene[IN_GAME].
                button[i].rect_tab[1]);
        else
            sfSprite_setTextureRect(game->def_scene[IN_GAME].button[i].
                b_sprite.img, game->def_scene[IN_GAME].button[i].
                rect_tab[0]);
    }
}

void defender_click_evt(window_t *win, game_t *game, int img)
{
    if (game->def_scene[IN_GAME].event.type == sfEvtMouseButtonReleased) {
        game->def_scene[IN_GAME].button[img].fct(&img, win, game);
        sfSprite_setTextureRect(game->def_scene[IN_GAME].button[img].
            b_sprite.img, game->def_scene[IN_GAME].button[img].rect_tab[1]);
    }
}

int defender_evt_mouse(window_t *win, game_t *game)
{
    int start = 0;
    int end = 0;

    for (int i = 0; hud[i].state != NOT_A_CELL; i++) {
        if (hud[i].state != game->level->hud) {
            start += hud[i].button_count;
        } else {
            end = start + hud[i].button_count;
            break;
        }
    }
    win->mouse_vect = sfMouse_getPositionRenderWindow(win->window);
    for (int i = start; i < end ||
        i < game->def_scene[IN_GAME].nb_button; i++) {
        if (sfFloatRect_contains(&(game->def_scene[IN_GAME].button[i].rect),
            win->mouse_vect.x, win->mouse_vect.y)) {
            sfSprite_setTextureRect(game->def_scene[IN_GAME].button[i].
                b_sprite.img, game->def_scene[IN_GAME].button[i].rect_tab[2]);
            defender_click_evt(win, game, i);
            return (1);
        }
    }
    return (0);
}

void check_viewpos(sfView *view)
{
    sfVector2f center = sfView_getCenter(view);
    if (center.x > 2270)
        center.x = 2270;
    else if (center.x < 760)
        center.x = 760;
    if (center.y < 540)
        center.y = 540;
    else if (center.y > 2750)
        center.y = 2750;
    sfView_setCenter(view, center);
}

void defender_key_handling(window_t *win, game_t *game)
{
    switch (game->def_scene[IN_GAME].event.key.code) {
        case sfKeyUp:
            sfView_move(game->view, (sfVector2f) {0, -30});
            break;
        case sfKeyDown:
            sfView_move(game->view, (sfVector2f) {0, 30});
            break;
        case sfKeyRight:
            sfView_move(game->view, (sfVector2f) {30, 0});
            break;
        case sfKeyLeft:
            sfView_move(game->view, (sfVector2f) {-30, 0});
            break;
        case sfKeyEscape:
            win->type_scene = PAUSE;
        default:
            break;
    }
    check_viewpos(game->view);
}

void defender_tile_selection(window_t *win, game_t *game)
{
    sfEvent evt = game->def_scene[IN_GAME].event;
    sfVector2i selected;
    sfVector2i pos;
    sfVector2f coord;

    pos = (sfVector2i) {evt.mouseButton.x, evt.mouseButton.y};
    coord = sfRenderWindow_mapPixelToCoords(win->window, pos, game->view);
    if (pos.x < 200)
        return;
    game->level->tile_s = (sfVector2i) {coord.x / 101, coord.y / 101};
    selected = game->level->tile_s;
    if (selected.x == MAP_SIZE/2 && selected.y == MAP_SIZE/2)
        game->level->hud = CASTLE_CELL;
    else if (is_tile_tower(selected, game->level->tower_list))
        game->level->hud = TOWER_CELL;
    else if (is_tile_portal(selected, game->level->portal_list))
        game->level->hud = PORTAL_CELL;
    else
        game->level->hud = EMPTY_CELL;
}

void defender_evt_poll(window_t *win, game_t *game)
{
    sfEvent evt = game->def_scene[IN_GAME].event;

    switch (evt.type) {
        case sfEvtClosed:
            sfRenderWindow_close(win->window);
            break;
        case sfEvtMouseButtonPressed :
            if (defender_evt_mouse(win, game))
                return;
            defender_tile_selection(win, game);
            break;
        case sfEvtMouseButtonReleased:
            defender_evt_mouse(win, game);
            break;
        case sfEvtKeyPressed:
            defender_key_handling(win, game);
            break;
        default:
            defender_mouse_over(win, game);
            break;
    }
}

int manage_event_defender(window_t *win, game_t *game)
{
    while (sfRenderWindow_pollEvent(win->window,
            &game->def_scene[IN_GAME].event)) {
        defender_evt_poll(win, game);
    }
    return (0);
}