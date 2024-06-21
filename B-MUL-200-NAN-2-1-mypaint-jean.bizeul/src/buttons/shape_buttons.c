/*
** EPITECH PROJECT, 2024
** paint
** File description:
** shape selection button's functions
*/

#include "../../include/main.h"

sfBool set_shape_square(void *data)
{
    paint_t *paint = data;

    paint->draw->shape = SQUARE;
    return sfTrue;
}

sfBool set_shape_circle(void *data)
{
    paint_t *paint = data;

    paint->draw->shape = CIRCLE;
    return sfTrue;
}
