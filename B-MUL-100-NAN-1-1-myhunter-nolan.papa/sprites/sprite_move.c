/*
** EPITECH PROJECT, 2023
** sprit move
** File description:
** animations of a sprite
*/

#include "../header.h"
#include <stdio.h>

void set_position(s_sprite *sp)
{
    int r;
    s_vector vec;

    srand(time(NULL));
    r = rand() % 250;
    vec.vector1.x = -76;
    vec.vector1.y = 250 + r;
    r = rand() % 500;
    vec.vector2.x = 1920;
    vec.vector2.y = 375 + r;
    r = rand() % 250;
    vec.vector3.x = -76;
    vec.vector3.y = 500 + r;
    sfSprite_setPosition(sp->sprite_star1, vec.vector1);
    sfSprite_setPosition(sp->sprite_star2, vec.vector2);
    sfSprite_setPosition(sp->sprite_star3, vec.vector3);
}

void set_rect(s_sprite *sp, s_rect *sr)
{
    sr->rect.top = 0;
    sr->rect.left = 0;
    sr->rect.width = 76;
    sr->rect.height = 76;
    sfSprite_setTexture(sp->sprite_star1, sp->texture_star1, sfTrue);
    sfSprite_setTextureRect(sp->sprite_star1, sr->rect);
    sfSprite_setTexture(sp->sprite_star2, sp->texture_star2, sfTrue);
    sfSprite_setTextureRect(sp->sprite_star2, sr->rect);
    sfSprite_setTexture(sp->sprite_star3, sp->texture_star3, sfTrue);
    sfSprite_setTextureRect(sp->sprite_star3, sr->rect);
    set_position(sp);
}

void clock_sprite(sfClock *clock, s_sprite *sp)
{
    sfTime time;
    double nb;

    time = sfClock_getElapsedTime(clock);
    nb = time.microseconds / 7500.0;
    if (nb > 1.0) {
        sprite_move(sp);
        sfClock_restart(clock);
    }
}

void sprite_move(s_sprite *sp)
{
    sfVector2f vector;

    vector.x = sfSprite_getPosition(sp->sprite_star1).x + 4.0;
    vector.y = sfSprite_getPosition(sp->sprite_star1).y - 0.25;
    sfSprite_setPosition(sp->sprite_star1, vector);
    vector.x = sfSprite_getPosition(sp->sprite_star2).x - 4.0;
    vector.y = sfSprite_getPosition(sp->sprite_star2).y - 0.25;
    sfSprite_setPosition(sp->sprite_star2, vector);
    vector.x = sfSprite_getPosition(sp->sprite_star3).x + 4.0;
    vector.y = sfSprite_getPosition(sp->sprite_star3).y - 0.25;
    sfSprite_setPosition(sp->sprite_star3, vector);
}
