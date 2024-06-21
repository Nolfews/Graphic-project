/*
** EPITECH PROJECT, 2024
** paint
** File description:
** display a quick guide on how to use gump
*/

#include "../../include/main.h"

static void draw_help_window(paint_t *paint)
{
    sfRenderWindow_clear(paint->top->help, (sfColor){125, 125, 200, 255});
    sfText_setCharacterSize(paint->top->text, 30);
    sfText_setPosition(paint->top->text, (sfVector2f){235, 10});
    sfText_setString(paint->top->text, "My_paint");
    sfRenderWindow_drawText(paint->top->help, paint->top->text, NULL);
    sfText_setPosition(paint->top->text, (sfVector2f){20, 100});
    sfText_setCharacterSize(paint->top->text, 11);
    sfText_setString(paint->top->text, "This is a simple copy of paint,\n"
        "you can change tools between pencil and rubber in the tool menu\n"
        "and save and create a new file in the file menu.");
    sfRenderWindow_drawText(paint->top->help, paint->top->text, NULL);
    sfText_setPosition(paint->top->text, (sfVector2f){20, 180});
    sfText_setString(paint->top->text, "You can draw in the bottom-left part\n"
        "and change the tool's size, shape and color in the righ part.");
    sfRenderWindow_drawText(paint->top->help, paint->top->text, NULL);
    sfRenderWindow_display(paint->top->help);
}

static sfBool manage_help_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            return sfFalse;
    }
    return sfTrue;
}

sfBool display_help_window(void *data)
{
    paint_t *paint = data;

    sfRenderWindow_setActive(paint->window, sfFalse);
    paint->top->help = create_renderwindow(720, 360, sfClose, "help");
    while (manage_help_events(paint->top->help) == sfTrue) {
        draw_help_window(paint);
    }
    sfRenderWindow_close(paint->top->help);
    sfRenderWindow_destroy(paint->top->help);
    sfRenderWindow_setActive(paint->window, sfTrue);
    return 0;
}
