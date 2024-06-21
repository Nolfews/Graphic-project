/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draw board
*/

#include "../../include/main.h"

void event_color(sfEvent *event, paint_t *paint)
{
    sfVector2f pPos = get_mouse_pos(paint->window);
    sfFloatRect bs = sfSprite_getGlobalBounds(paint->side->color);
    sfVector2f lPos;
    sfColor new_color;

    if (event->mouseButton.button == sfMouseLeft) {
        if (sfFloatRect_contains(&bs, pPos.x, pPos.y)) {
            lPos = (sfVector2f){pPos.x - bs.left, pPos.y - bs.top};
            new_color = sfImage_getPixel(sfTexture_copyToImage(
                sfSprite_getTexture(paint->side->color)),
                (unsigned int)lPos.x * 1 / 0.35,
                (unsigned int)lPos.y * 1 / 0.35);
            paint->draw->color = new_color;
        }
    }
}
