/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** start_defender
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include "struct_defender.h"
#include "defender.h"
#include "dico_defender.h"

animation_t *create_animation(spritesheet_t *ss, float duration, sfBool repeat)
{
    animation_t *anim = malloc(sizeof(animation_t));

    anim->spritesheet = ss;
    anim->duration = duration;
    anim->sprite = sfSprite_create();
    sfSprite_setTexture(anim->sprite, anim->spritesheet->texture, 0);
    sfSprite_setTextureRect(anim->sprite, (sfIntRect) {0, 0,
        anim->spritesheet->width, 100});
    anim->clock = sfClock_create();
    anim->state = 0;
    anim->repeat = repeat;

    return (anim);
}

animation_t *copy_animation(animation_t *original)
{
    animation_t *copy = malloc(sizeof(animation_t));

    copy->spritesheet = original->spritesheet;
    copy->duration = original->duration;
    copy->sprite = sfSprite_copy(original->sprite);
    copy->state = 0;
    copy->clock = sfClock_create();
    copy->repeat = original->repeat;

    return (copy);
}

void next_anim(animation_t *anim)
{
    sfTime time = sfClock_getElapsedTime(anim->clock);
    float time_between =
        ((anim->duration / anim->spritesheet->sprite_count) * 1000000);
    int width = anim->spritesheet->width;
    sfIntRect new;

    if (time.microseconds < time_between)
        return;
    sfClock_restart(anim->clock);
    anim->state = anim->state + 1;
    if (anim->state > anim->spritesheet->sprite_count && anim->repeat)
        anim->state = 0;
    new.left = anim->state * width;
    new.top = 0;
    new.width = width;
    new.height = 100;
    sfSprite_setTextureRect(anim->sprite, new);
}

void draw_anim(animation_t *anim, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, anim->sprite, 0);
    next_anim(anim);
}

void destroy_animation(animation_t *anim)
{
    sfSprite_destroy(anim->sprite);
    sfClock_destroy(anim->clock);
    free(anim);
    anim = NULL;
}