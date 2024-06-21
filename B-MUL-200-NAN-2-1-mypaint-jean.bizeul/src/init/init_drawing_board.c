/*
** EPITECH PROJECT, 2024
** paint
** File description:
** inits the drawing board
*/

#include "../../include/main.h"

static sfRectangleShape *init_background(void)
{
    sfRectangleShape *back = sfRectangleShape_create();

    sfRectangleShape_setPosition(back, (sfVector2f){10, 50});
    sfRectangleShape_setSize(back, (sfVector2f){730, 586});
    sfRectangleShape_setFillColor(back, sfWhite);
    sfRectangleShape_setOutlineColor(back, (sfColor){200, 200, 200, 255});
    sfRectangleShape_setOutlineThickness(back, 5);
    return back;
}

layer_t *create_layer(void)
{
    layer_t *layer = malloc(sizeof(layer_t));

    layer->img_img = sfImage_createFromColor(720, 576, sfTransparent);
    layer->img_text = sfTexture_createFromImage(layer->img_img, NULL);
    layer->img_spr = sfSprite_create();
    sfSprite_setTexture(layer->img_spr, layer->img_text, sfFalse);
    sfSprite_setPosition(layer->img_spr, (sfVector2f){16, 55});
    return layer;
}

board_t *init_drawing_board(void)
{
    board_t *board = malloc(sizeof(board_t));

    board->backgr = init_background();
    board->begin = malloc(sizeof(layer_t *));
    *board->begin = NULL;
    board->end = malloc(sizeof(layer_t *));
    *board->end = NULL;
    board->layer = 0;
    add_layer_from_end(create_layer(), board->end, board->begin);
    board->state = NONE;
    board->shape = CIRCLE;
    board->tool_size = 10;
    board->color = sfBlack;
    return board;
}
