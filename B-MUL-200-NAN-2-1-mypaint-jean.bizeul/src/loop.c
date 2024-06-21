/*
** EPITECH PROJECT, 2024
** paint
** File description:
** loop
*/

#include "../include/main.h"

int main_loop(paint_t *paint)
{
    while (manage_events(paint)) {
        sfRenderWindow_clear(paint->window, (sfColor){125, 125, 125, 255});
        draw(paint);
        sfRenderWindow_display(paint->window);
        do_buttons_actions(paint);
    }
    return 1;
}
