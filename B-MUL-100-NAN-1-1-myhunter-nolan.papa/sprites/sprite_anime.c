/*
** EPITECH PROJECT, 2023
** sprite anime
** File description:
** sprite anime
*/

#include "../header.h"

void sprite_anime(sfClock *clock, s_sprite *sp, s_rect *sr)
{
    sfTime time;
    double nb;

    time = sfClock_getElapsedTime(clock);
    nb = time.microseconds / 150000.0;
    if (nb > 1.0) {
        sr->rect.left += 76;
        if (sr->rect.left > 76) {
            sr->rect.left = 0;
        }
        sfClock_restart(clock);
    }
    sfSprite_setTextureRect(sp->sprite_star1, sr->rect);
    sfSprite_setTextureRect(sp->sprite_star2, sr->rect);
    sfSprite_setTextureRect(sp->sprite_star3, sr->rect);
}
