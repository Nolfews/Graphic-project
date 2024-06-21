/*
** EPITECH PROJECT, 2024
** paint
** File description:
** opens a file given it's relative or absolute path
*/

#include "../../include/main.h"

/*
**   static sfBool open_file_by_filepath(char *filepath, paint_t *paint,
**       int pos)
**    {
**        layer_t *layer = *paint->draw->begin;
**        sfImage *img = NULL;
**
**        filepath[pos - 1] = '\0';
**        img = sfImage_createFromFile(filepath);
**        if (img == NULL)
**            return sfFalse;
**        delete_all_layers(paint->draw->end, paint->draw->begin);
**        sfImage_destroy(layer->img_img);
**        layer->img_img = img;
**        sfTexture_updateFromImage(layer->img_text, layer->img_img, 0, 0);
**        return sfTrue;
**    }
*/

static void draw_open_window(paint_t *paint, char *input)
{
    sfRenderWindow_clear(paint->top->open, (sfColor){50, 125, 125, 255});
    sfText_setCharacterSize(paint->top->text, 25);
    sfText_setString(paint->top->text,
        "Not working yet,\nyou can close the window.");
    sfText_setPosition(paint->top->text, (sfVector2f){10, 25});
    sfRenderWindow_drawText(paint->top->open, paint->top->text, NULL);
    sfText_setCharacterSize(paint->top->text, 15);
    sfText_setString(paint->top->text,
        "Format : FILENAME.EXTENSION\nExpansions : .png .bmp .tga .jpg");
    sfText_setPosition(paint->top->text, (sfVector2f){60, 120});
    sfRenderWindow_drawText(paint->top->open, paint->top->text, NULL);
    sfText_setCharacterSize(paint->top->text, 18);
    sfText_setString(paint->top->text, input);
    sfText_setPosition(paint->top->text, (sfVector2f){60, 200});
    sfRenderWindow_drawText(paint->top->open, paint->top->text, NULL);
    sfRenderWindow_display(paint->top->open);
}

static void update_filename(char *name, int *pos, sfTextEvent *event)
{
    unsigned char c = event->unicode;

    if (c <= 0 || c > 127 || c == '\n')
        return;
    if (c == '\b' && *pos > 0) {
        *pos -= 1;
        if (*pos == 24)
            *pos = 23;
        name[*pos] = '\0';
    }
    if (*pos <= 23 && c != '\b') {
        name[*pos] = c;
        *pos += 1;
    }
}

static sfBool manage_open_events(paint_t *paint, char *input, int *pos)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(paint->top->open, &event)) {
        if (event.type == sfEvtClosed)
            return sfTrue;
        if (event.type == sfEvtTextEntered)
            update_filename(input, pos, &event.text);
    }
    return sfFalse;
}

sfBool open_file(void *data)
{
    paint_t *paint = data;
    char input[24] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int pos = 0;

    sfRenderWindow_setActive(paint->window, sfFalse);
    paint->top->open = create_renderwindow(600, 400, sfClose, "open");
    while (manage_open_events(paint, input, &pos) == sfFalse) {
        draw_open_window(paint, input);
    }
    sfRenderWindow_destroy(paint->top->open);
    sfRenderWindow_setActive(paint->window, sfTrue);
    return 0;
}
