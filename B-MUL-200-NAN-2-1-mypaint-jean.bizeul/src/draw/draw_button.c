/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draws a button
*/

#include "../../include/main.h"

void draw_button(sfRenderWindow *window, button_t *button)
{
    if (IS_RELEASED(button))
        button->text_rect.top = 0;
    if (IS_HOVER(button))
        button->text_rect.top = 32;
    if (IS_PRESSED(button))
        button->text_rect.top = 64;
    sfSprite_setTextureRect(button->sprite, button->text_rect);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
}
