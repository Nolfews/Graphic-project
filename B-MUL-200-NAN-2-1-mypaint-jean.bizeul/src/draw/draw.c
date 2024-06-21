/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draws stuff
*/

#include "../../include/main.h"

void draw(paint_t *paint)
{
    draw_board(paint);
    draw_top_bar(paint);
    draw_side_menu(paint);
    draw_text(paint);
}
