/*
** EPITECH PROJECT, 2024
** paint
** File description:
** function used to save the board as .jpg, .png or .bmp
*/

#include "../../include/main.h"

static void draw_save_window(paint_t *paint, char *input)
{
    sfRenderWindow_clear(paint->top->save, (sfColor){125, 125, 125, 255});
    sfText_setString(paint->top->text, "Enter a file name.");
    sfText_setCharacterSize(paint->top->text, 30);
    sfText_setPosition(paint->top->text, (sfVector2f){60, 25});
    sfRenderWindow_drawText(paint->top->save, paint->top->text, NULL);
    sfText_setCharacterSize(paint->top->text, 15);
    sfText_setString(paint->top->text,
        "Format : FILENAME.EXTENSION\nExpansions : .png .bmp .tga .jpg");
    sfText_setPosition(paint->top->text, (sfVector2f){60, 120});
    sfRenderWindow_drawText(paint->top->save, paint->top->text, NULL);
    sfText_setCharacterSize(paint->top->text, 18);
    sfText_setString(paint->top->text, input);
    sfText_setPosition(paint->top->text, (sfVector2f){60, 200});
    sfRenderWindow_drawText(paint->top->save, paint->top->text, NULL);
    sfRenderWindow_display(paint->top->save);
}

static void update_filename(char *name, int *pos, sfTextEvent *event)
{
    unsigned char c = event->unicode;

    if (c <= 0 || c > 127 || c == 13)
        return;
    if (c == '\b' && *pos > 0) {
        *pos -= 1;
        if (*pos == 24)
            *pos = 23;
        name[*pos] = '\0';
    }
    if (*pos < 23 && c != '\b') {
        name[*pos] = c;
        *pos += 1;
    }
}

static sfBool save_file(char *name, paint_t *paint)
{
    layer_t *layer = *paint->draw->begin;

    if (sfImage_saveToFile(layer->img_img, name)) {
        return sfTrue;
    } else {
        return sfFalse;
    }
}

static sfBool manage_save_events(paint_t *paint, char *input, int *pos)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(paint->top->save, &event)) {
        if (event.type == sfEvtClosed)
            return sfTrue;
        if (event.type == sfEvtTextEntered && event.text.unicode != 13)
            update_filename(input, pos, &event.text);
        if (event.type == sfEvtTextEntered && event.text.unicode == 13
            && save_file(input, paint))
            return sfTrue;
    }
    return sfFalse;
}

sfBool save_layers_as_file(void *data)
{
    paint_t *paint = data;
    char input[24] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int pos = 0;

    sfRenderWindow_setActive(paint->window, sfFalse);
    paint->top->save = create_renderwindow(600, 400, sfClose, "save");
    while (manage_save_events(paint, input, &pos) == sfFalse) {
        draw_save_window(paint, input);
    }
    sfRenderWindow_destroy(paint->top->save);
    sfRenderWindow_setActive(paint->window, sfTrue);
    return 0;
}
