/*
** EPITECH PROJECT, 2023
** set sprite
** File description:
** set sprite
*/

#include "../header.h"

int set_sprite(sfRenderWindow *window, s_sprite *sp, s_rect *sr)
{
    sp->texture_star1 = sfTexture_createFromFile("sprites/stars.png", NULL);
    if (!sp->texture_star1)
        return (84);
    sp->sprite_star1 = sfSprite_create();
    sp->texture_star2 = sfTexture_createFromFile("sprites/stars.png", NULL);
    if (!sp->texture_star2)
        return (84);
    sp->sprite_star2 = sfSprite_create();
    sp->texture_star3 = sfTexture_createFromFile("sprites/stars.png", NULL);
    if (!sp->texture_star3)
        return (84);
    sp->sprite_star3 = sfSprite_create();
    set_rect(sp, sr);
}
