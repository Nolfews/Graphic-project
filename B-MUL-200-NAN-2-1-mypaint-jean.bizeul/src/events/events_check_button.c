/*
** EPITECH PROJECT, 2024
** paint
** File description:
** check if a button is pressed/hovered/released or not
*/

#include "../../include/main.h"

static void update_button_hovered(button_t *button, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfVector2f cursor = get_mouse_pos(window);

    if (cursor.x >= pos.x && cursor.x < pos.x + 64
        && cursor.y >= pos.y && cursor.y < pos.y + 32) {
        button->state = HOVER;
    } else {
        button->state = RELEASED;
    }
}

static void update_button_pressed(button_t *button, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfVector2f cursor = get_mouse_pos(window);

    if (cursor.x >= pos.x && cursor.x < pos.x + 64
        && cursor.y >= pos.y && cursor.y < pos.y + 32) {
        button->state = PRESSED;
    } else {
        button->state = RELEASED;
    }
}

static void update_button_released(button_t *button, sfRenderWindow *window)
{
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfVector2f cursor = get_mouse_pos(window);

    if (cursor.x >= pos.x && cursor.x < pos.x + 64
        && cursor.y >= pos.y && cursor.y < pos.y + 32) {
        button->state = HOVER;
    } else {
        button->state = RELEASED;
    }
}

void update_button(sfEvent *event, button_t *button, sfRenderWindow *window)
{
    if (event->type == sfEvtMouseButtonReleased)
        update_button_released(button, window);
    if (event->type == sfEvtMouseMoved)
        update_button_hovered(button, window);
    if (event->type == sfEvtMouseButtonPressed)
        update_button_pressed(button, window);
}
