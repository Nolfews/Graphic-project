/*
** EPITECH PROJECT, 2024
** paint
** File description:
** size managements button's functions
*/

#include "../../include/main.h"

sfBool increase_size(void *data)
{
    paint_t *paint = data;

    if (paint->draw->tool_size < 50) {
        paint->draw->tool_size += 1;
        return sfTrue;
    } else {
        return sfFalse;
    }
}

sfBool decrease_size(void *data)
{
    paint_t *paint = data;

    if (paint->draw->tool_size > 1) {
        paint->draw->tool_size -= 1;
        return sfTrue;
    } else {
        return sfFalse;
    }
}
