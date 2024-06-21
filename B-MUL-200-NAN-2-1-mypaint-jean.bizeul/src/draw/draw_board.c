/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draw board
*/

#include "../../include/main.h"

void draw_board(paint_t *paint)
{
    layer_t *layer = *paint->draw->begin;

    sfRenderWindow_drawRectangleShape(paint->window,
        paint->draw->backgr, NULL);
    sfRenderWindow_drawSprite(paint->window, layer->img_spr, NULL);
}
