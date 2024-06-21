/*
** EPITECH PROJECT, 2023
** background
** File description:
** background
*/

#include "../header.h"

int set_background(sfRenderWindow *win, s_sprite *sp, s_music *ms, s_rect *sr)
{
    sp->texture_bg = sfTexture_createFromFile("sprites/background.jpg", NULL);
    if (!sp->texture_bg)
        return (84);
    sp->sprite_bg = sfSprite_create();
    sfSprite_setTexture(sp->sprite_bg, sp->texture_bg, sfTrue);
    play_music(ms);
    set_sprite(win, sp, sr);
}
