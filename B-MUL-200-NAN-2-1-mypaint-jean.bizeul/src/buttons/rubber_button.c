/*
** EPITECH PROJECT, 2024
** paint
** File description:
** change the tool for rubber
*/

#include "../../include/main.h"

sfBool set_tool_to_rubber(void *data)
{
    paint_t *paint = data;

    paint->draw->color = sfTransparent;
    paint->draw->shape = CIRCLE;
    paint->draw->tool_size = 10;
    return 0;
}
