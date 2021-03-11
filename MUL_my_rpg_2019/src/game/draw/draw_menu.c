/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** draw_menu
*/

#include "rpg.h"
#include "rpg_struct.h"
#include "rpg_dico.h"
#include "my.h"

void animate_menu(glo_t *gl)
{
    sfTime time = sfClock_restart(gl->anim_clock);
    sfInt64 delta = sfTime_asMilliseconds(time);
    static long wait = 0;

    gl->counter += delta;
    wait += delta;
    if (wait < 32)
        return;
    wait = 0;
    gl->pos_x += 500;
    if (gl->pos_x >= 2500){
        gl->pos_x = 0;
        gl->pos_y += 500;
    }
    if (gl->pos_y >= 6000)
        gl->pos_y = 0;
    sfSprite_setTextureRect(gl->anim, (sfIntRect) {gl->pos_x, gl->pos_y, 500, 500});
}

int draw_menu(glo_t *gl)
{
    menu_event(gl);
    animate_menu(gl);
    sfRenderWindow_drawSprite(gl->win.window, gl->anim, 0);
    if (gl->counter < 5000)
        return (0);
    draw_scene_sprite(&gl->win, &gl->scenes[MENU]);
    draw_scene_button(&gl->win, &gl->scenes[MENU]);
    return (0);
}

int draw_game(glo_t *gl)
{
    main_event(gl);
    game_loop(gl->win.window, gl->data);
    return (0);
}
