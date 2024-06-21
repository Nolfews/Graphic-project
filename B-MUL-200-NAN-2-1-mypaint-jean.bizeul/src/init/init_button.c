/*
** EPITECH PROJECT, 2024
** paint
** File description:
** initialise a button struct
*/

#include "../../include/main.h"

button_t *init_button(sfTexture *texture, sfVector2f pos, sfVector2f scale,
    sfIntRect text_rect)
{
    button_t *button = malloc(sizeof(button_t));

    button->state = NONE;
    button->text_rect = (text_rect);
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, texture, sfFalse);
    sfSprite_setTextureRect(button->sprite, button->text_rect);
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setScale(button->sprite, scale);
    return button;
}
