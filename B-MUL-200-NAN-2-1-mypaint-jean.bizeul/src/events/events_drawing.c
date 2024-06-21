/*
** EPITECH PROJECT, 2024
** paint
** File description:
** functions used to draw on the actual layer
*/

#include "../../include/main.h"

sfBool is_cursor_on_board(sfRenderWindow *window)
{
    sfVector2f pos = get_mouse_pos(window);

    if (pos.x >= 16 && pos.x < 736 && pos.y >= 55 && pos.y < 631) {
        return sfTrue;
    } else {
        return sfFalse;
    }
}

static void update_drawing_state(sfEvent *event, paint_t *paint)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (is_cursor_on_board(paint->window)) {
            paint->draw->state = PRESSED;
        } else
            paint->draw->state = RELEASED;
        return;
    }
    if (event->type == sfEvtMouseButtonReleased) {
        paint->draw->state = RELEASED;
    }
}

void update_board(sfEvent *event, paint_t *paint)
{
    update_drawing_state(event, paint);
    if (paint->draw->state == PRESSED) {
        paint->draw->last_pos = paint->draw->pos;
        paint->draw->pos = get_mouse_pos(paint->window);
    } else {
        paint->draw->last_pos = (sfVector2f){-1, -1};
        paint->draw->pos = (sfVector2f){-1, -1};
    }
    if (event->type == sfEvtMouseMoved)
        draw_on_board(paint->draw);
    if (event->type == sfEvtMouseButtonPressed) {
        draw_shape(paint->draw, (sfVector2f){get_mouse_pos(paint->window).x
            - 15, get_mouse_pos(paint->window).y - 55});
        draw_shape(paint->draw, (sfVector2f){get_mouse_pos(paint->window).x
            - 15, get_mouse_pos(paint->window).y - 56});
        draw_shape(paint->draw, (sfVector2f){get_mouse_pos(paint->window).x
            - 16, get_mouse_pos(paint->window).y - 55});
        draw_shape(paint->draw, (sfVector2f){get_mouse_pos(paint->window).x
            - 16, get_mouse_pos(paint->window).y - 56});
    }
}
