/*
** EPITECH PROJECT, 2024
** paint
** File description:
** initialisation's main file
*/

#include "../../include/main.h"

paint_t *init_paint_struct(void)
{
    paint_t *paint = malloc(sizeof(paint_t));

    paint->textures = init_textures();
    if (paint->textures == NULL)
        return NULL;
    paint->top = init_top_bar(paint->textures);
    paint->draw = init_drawing_board();
    paint->side = init_side_menu(paint);
    paint->window = create_renderwindow(1080, 720, sfClose | sfResize, "gump");
    if (paint->top == NULL || paint->draw == NULL || paint->side == NULL)
        return NULL;
    return paint;
}
