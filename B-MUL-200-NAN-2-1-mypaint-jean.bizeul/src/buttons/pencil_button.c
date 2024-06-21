/*
** EPITECH PROJECT, 2024
** paint
** File description:
** change the tool to pen
*/

#include "../../include/main.h"

sfBool set_tool_to_pencil(void *data)
{
    paint_t *paint = data;

    paint->draw->color = sfBlack;
    paint->draw->shape = CIRCLE;
    paint->draw->tool_size = 10;
    return 0;
}
