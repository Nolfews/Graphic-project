/*
** EPITECH PROJECT, 2023
** analyse events
** File description:
** analyse these events make a function
*/

#include "../header.h"

static void new_position_sprite1(s_sprite *sp)
{
    int r;
    s_vector vec;

    srand(time(NULL));
    r = rand() % 800;
    vec.vector1.x = -76;
    vec.vector1.y = 200 + r;
    sfSprite_setPosition(sp->sprite_star1, vec.vector1);
}

static void new_position_sprite2(s_sprite *sp)
{
    int r;
    s_vector vec;

    srand(time(NULL));
    r = rand() % 800;
    vec.vector2.x = 1920;
    vec.vector2.y = 200 + r;
    sfSprite_setPosition(sp->sprite_star2, vec.vector2);
}

static void new_position_sprite3(s_sprite *sp)
{
    int r;
    s_vector vec;

    srand(time(NULL));
    r = rand() % 800;
    vec.vector3.x = -76;
    vec.vector3.y = 1000 - r;
    sfSprite_setPosition(sp->sprite_star3, vec.vector3);
}

void check_pos_sprite(s_sprite *sp)
{
    sfVector2f vec;

    vec.x = sfSprite_getPosition(sp->sprite_star1).x;
    vec.y = sfSprite_getPosition(sp->sprite_star1).y;
    if (vec.x > 1920 || vec.y < 0) {
        new_position_sprite1(sp);
    }
    vec.x = sfSprite_getPosition(sp->sprite_star2).x;
    vec.y = sfSprite_getPosition(sp->sprite_star2).y;
    if (vec.x < 0 || vec.y < 0) {
        new_position_sprite2(sp);
    }
    vec.x = sfSprite_getPosition(sp->sprite_star3).x;
    vec.y = sfSprite_getPosition(sp->sprite_star3).y;
    if (vec.x > 1920 || vec.y < 0) {
        new_position_sprite3(sp);
    }
}

static void check_hit(int nb, s_sprite *sp)
{
    if (nb == 1)
        new_position_sprite1(sp);
    if (nb == 10)
        new_position_sprite2(sp);
    if (nb == 11) {
        new_position_sprite1(sp);
        new_position_sprite2(sp);
    }
    if (nb == 100)
        new_position_sprite3(sp);
    if (nb == 101) {
        new_position_sprite1(sp);
        new_position_sprite3(sp);
    }
    if (nb == 111) {
        new_position_sprite1(sp);
        new_position_sprite2(sp);
        new_position_sprite3(sp);
    }
}

void hit_sprite(sfMouseButtonEvent event, sfRenderWindow *win, s_sprite *sp)
{
    sfVector2f vec_star1 = sfSprite_getPosition(sp->sprite_star1);
    sfVector2f vec_star2 = sfSprite_getPosition(sp->sprite_star2);
    sfVector2f vec_star3 = sfSprite_getPosition(sp->sprite_star3);
    int nb = 0;

    if (event.x >= vec_star1.x && event.x <= (vec_star1.x + 76)) {
        if (event.y >= vec_star1.y && event.y <= (vec_star1.y + 76))
            nb = nb + 1;
    }
    if (event.x >= vec_star2.x && event.x <= (vec_star2.x + 76)) {
        if (event.y >= vec_star2.y && event.y <= (vec_star2.y + 76))
            nb = nb + 10;
    }
    if (event.x >= vec_star3.x && event.x <= (vec_star3.x + 76)) {
        if (event.y >= vec_star3.y && event.y <= (vec_star3.y + 76))
            nb = nb + 100;
    }
    check_hit(nb, sp);
}

void analyse_events(sfRenderWindow *window, s_sprite *sp)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        switch (event.type) {
        case sfEvtClosed:
            close_window(window);
            break;
        case sfEvtMouseButtonPressed:
            hit_sprite(event.mouseButton, window, sp);
            break;
        default:
            break;
        }
    }
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
