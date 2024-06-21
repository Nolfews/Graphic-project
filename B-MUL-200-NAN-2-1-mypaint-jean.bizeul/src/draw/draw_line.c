/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draws a line between two points using the Bresenham's line algorithm.
*/

#include "../../include/main.h"

static void draw_circle(sfImage *img, int size, sfVector2i pos,
    sfColor color)
{
    for (float ang = 0; ang <= 6.5; ang += (1 / (float)size)){
        if (cos(ang) * size + pos.x >= 0
            && sin(ang) * size + pos.y >= 0
            && cos(ang) * size + pos.x < 720
            && sin(ang) * size + pos.y < 576) {
            sfImage_setPixel(img, cos(ang) * size + pos.x,
                sin(ang) * size + pos.y, color);
        }
    }
}

static void draw_vertical_line(sfImage *img, int size, sfVector2i pos,
    sfColor color)
{
    for (int y = pos.y; y < pos.y + size; y ++) {
        if (pos.x - size / 2 >= 0 && y - size / 2 >= 0
            && pos.x - size / 2 < 720 && y - size / 2 < 576) {
            sfImage_setPixel(img, pos.x - size / 2, y - size / 2, color);
        }
    }
}

void draw_shape(board_t *board, sfVector2f pos)
{
    layer_t *layer = *board->begin;

    if (board->shape == SQUARE) {
        for (int x = pos.x; x < pos.x + board->tool_size; x ++) {
            draw_vertical_line(layer->img_img, board->tool_size,
                (sfVector2i){x, pos.y}, board->color);
        }
    }
    if (board->shape == CIRCLE) {
        for (int size = board->tool_size; size > 0; size --) {
            draw_circle(layer->img_img, size, (sfVector2i){pos.x, pos.y},
                board->color);
        }
    }
    sfTexture_updateFromImage(layer->img_text, layer->img_img, 0, 0);
}

static void draw_line_low(sfVector2i pos0, sfVector2i pos1, board_t *board)
{
    int dx = pos1.x - pos0.x;
    int dy = pos1.y - pos0.y;
    int yi = 1;
    int y = 0;
    int d = 0;

    if (dy < 0) {
        yi = -1;
        dy = -dy;
    }
    d = (2 * dy) - dx;
    y = pos0.y;
    for (int x = pos0.x; x < pos1.x; x ++) {
        draw_shape(board, (sfVector2f){x, y});
        if (d > 0) {
            y += yi;
            d += 2 * (dy - dx);
        } else
            d += 2 * dy;
    }
}

static void draw_line_high(sfVector2i pos0, sfVector2i pos1, board_t *board)
{
    int dx = pos1.x - pos0.x;
    int dy = pos1.y - pos0.y;
    int xi = 1;
    int x = 0;
    int d = 0;

    if (dx < 0) {
        xi = -1;
        dx = -dx;
    }
    d = (2 * dx) - dy;
    x = pos0.x;
    for (int y = pos0.y; y < pos1.y; y ++) {
        draw_shape(board, (sfVector2f){x, y});
        if (d > 0) {
            x += xi;
            d += 2 * (dx - dy);
        } else
            d += 2 * dx;
    }
}

static void draw_line(board_t *board)
{
    int x0 = board->last_pos.x - 16;
    int y0 = board->last_pos.y - 55;
    int x1 = board->pos.x - 16;
    int y1 = board->pos.y - 55;
    sfVector2i pos0 = {x0, y0};
    sfVector2i pos1 = {x1, y1};

    if (abs(y1 - y0) < abs(x1 - x0)) {
        if (x0 > x1)
            draw_line_low(pos1, pos0, board);
        else
            draw_line_low(pos0, pos1, board);
    } else {
        if (y0 > y1)
            draw_line_high(pos1, pos0, board);
        else
            draw_line_high(pos0, pos1, board);
    }
}

void draw_on_board(board_t *board)
{
    if (board->state != PRESSED)
        return;
    if (board->last_pos.x == -1)
        return;
    draw_line(board);
}
