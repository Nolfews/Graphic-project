/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draws text
*/

#include "../../include/main.h"

void draw_text(paint_t *paint)
{
    sfText_setPosition(paint->side->text, (sfVector2f){760, 50});
    sfRenderWindow_drawText(paint->window, paint->side->text, NULL);
}
