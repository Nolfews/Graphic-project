/*
** EPITECH PROJECT, 2024
** paint
** File description:
** functions to create and delete layer
*/

#include "../include/main.h"

void add_layer_from_end(layer_t *layer, layer_t **end, layer_t **begin)
{
    layer_t *last = *end;

    if (last == NULL) {
        layer->id = 0;
    } else {
        layer->id = last->id + 1;
    }
    layer->next = NULL;
    layer->last = *end;
    if (*begin == NULL)
        *begin = layer;
    *end = layer;
}

void delete_all_layers(layer_t **end, layer_t **begin)
{
    layer_t *actual = *begin;

    while (actual != NULL && actual->next != NULL) {
        *begin = actual->next;
        actual->next->last = NULL;
        sfSprite_destroy(actual->img_spr);
        sfTexture_destroy(actual->img_text);
        sfImage_destroy(actual->img_img);
        free(actual);
    }
    *end = NULL;
    *begin = NULL;
}
