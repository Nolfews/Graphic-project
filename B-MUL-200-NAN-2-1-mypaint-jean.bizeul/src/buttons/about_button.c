/*
** EPITECH PROJECT, 2024
** paint
** File description:
** display infos about the project itself
*/

#include "../../include/main.h"

static void draw_help_window(paint_t *paint)
{
    sfRenderWindow_clear(paint->top->about, (sfColor){125, 200, 125, 255});
    sfText_setCharacterSize(paint->top->text, 30);
    sfText_setPosition(paint->top->text, (sfVector2f){20, 10});
    sfText_setString(paint->top->text, "About my_paint");
    sfRenderWindow_drawText(paint->top->about, paint->top->text, NULL);
    sfText_setPosition(paint->top->text, (sfVector2f){80, 300});
    sfText_setString(paint->top->text, "Have fun !");
    sfRenderWindow_drawText(paint->top->about, paint->top->text, NULL);
    sfText_setPosition(paint->top->text, (sfVector2f){20, 100});
    sfText_setCharacterSize(paint->top->text, 11);
    sfText_setString(paint->top->text, "This is a school project\n"
        "which aims to reproduce paint/gimp.");
    sfRenderWindow_drawText(paint->top->about, paint->top->text, NULL);
    sfText_setPosition(paint->top->text, (sfVector2f){20, 180});
    sfText_setString(paint->top->text, "Contributors :\n"
        "   Nolan Papa  : nolan.papa@epitech.eu\n" \
        "   Jean Bizeul : jean.bizeul@epitech.eu");
    sfRenderWindow_drawText(paint->top->about, paint->top->text, NULL);
    sfRenderWindow_display(paint->top->about);
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

sfBool display_about_window(void *data)
{
    paint_t *paint = data;

    sfRenderWindow_setActive(paint->window, sfFalse);
    paint->top->about = create_renderwindow(480, 360, sfClose, "help");
    while (manage_help_events(paint->top->about) == sfTrue) {
        draw_help_window(paint);
    }
    sfRenderWindow_close(paint->top->about);
    sfRenderWindow_destroy(paint->top->about);
    sfRenderWindow_setActive(paint->window, sfTrue);
    return 0;
}
