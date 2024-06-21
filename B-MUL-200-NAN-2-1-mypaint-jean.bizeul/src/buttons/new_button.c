/*
** EPITECH PROJECT, 2024
** paint
** File description:
** resets the canva
*/

#include "../../include/main.h"

sfBool reset_layers(void *data)
{
    paint_t *paint = data;

    delete_all_layers(paint->draw->end, paint->draw->begin);
    add_layer_from_end(create_layer(), paint->draw->end, paint->draw->begin);
    return sfTrue;
}
