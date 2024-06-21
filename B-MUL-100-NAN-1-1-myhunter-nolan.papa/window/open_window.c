/*
** EPITECH PROJECT, 2023
** open window
** File description:
** CSFML initiation
*/

#include "../header.h"
#include <stdio.h>

static void destroy_all_prites(s_sprite *sp)
{
    sfSprite_destroy(sp->sprite_bg);
    sfTexture_destroy(sp->texture_bg);
    sfSprite_destroy(sp->sprite_star1);
    sfTexture_destroy(sp->texture_star1);
    sfSprite_destroy(sp->sprite_star2);
    sfTexture_destroy(sp->texture_star2);
    sfSprite_destroy(sp->sprite_star3);
    sfTexture_destroy(sp->texture_star3);
}

void destroy_all(sfRenderWindow *win, s_music *ms, sfClock *c1, sfClock *c2)
{
    sfRenderWindow_destroy(win);
    sfMusic_destroy(ms->music_game);
    sfClock_destroy(c1);
    sfClock_destroy(c2);
}

sfRenderWindow *set_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(mode, "my_hunt", sfResize | sfClose, NULL);
    return (window);
}

void refresh_all(sfRenderWindow *window, s_sprite *sp)
{
    sfRenderStates *stat;

    check_pos_sprite(sp);
    sfRenderWindow_clear(window, sfBlack);
    draw_sprite(window, sp);
    sfRenderWindow_display(window);
}

int open_window(void)
{
    sfRenderWindow *window = set_window();
    s_sprite sp;
    s_rect sr;
    s_music ms;
    sfClock *clock_anime = sfClock_create();
    sfClock *clock_sp = sfClock_create();

    sfRenderWindow_setFramerateLimit(window, 60);
    set_background(window, &sp, &ms, &sr);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, &sp);
        sprite_anime(clock_anime, &sp, &sr);
        clock_sprite(clock_sp, &sp);
        refresh_all(window, &sp);
    }
    destroy_all(window, &ms, clock_anime, clock_sp);
    destroy_all_prites(&sp);
}
