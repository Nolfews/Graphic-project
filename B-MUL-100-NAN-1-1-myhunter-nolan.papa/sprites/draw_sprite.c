/*
** EPITECH PROJECT, 2023
** draw sprite
** File description:
** draw sprite
*/

#include "../header.h"

void draw_sprite(sfRenderWindow *window, s_sprite *sp)
{
    sfRenderWindow_drawSprite(window, sp->sprite_bg, NULL);
    sfRenderWindow_drawSprite(window, sp->sprite_star1, NULL);
    sfRenderWindow_drawSprite(window, sp->sprite_star2, NULL);
    sfRenderWindow_drawSprite(window, sp->sprite_star3, NULL);
}
