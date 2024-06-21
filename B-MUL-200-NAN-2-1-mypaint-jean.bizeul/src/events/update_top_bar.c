/*
** EPITECH PROJECT, 2024
** paint
** File description:
** update the status of the top bar
*/

#include "../../include/main.h"

static sfBool is_list_active(linked_list_t **buttons, sfEvent *event,
    sfRenderWindow *window)
{
    linked_list_t *actual = *buttons;
    button_t *button = NULL;
    sfBool is_active = sfFalse;

    while (actual != NULL) {
        button = actual->data;
        update_button(event, button, window);
        if (IS_HOVER(button) || IS_PRESSED(button))
            is_active = sfTrue;
        actual = actual->next;
    }
    return is_active;
}

static void update_scroll(menu_scrolling_t *scroll, sfEvent *event,
    sfRenderWindow *window)
{
    sfBool is_active = is_list_active(scroll->buttons, event, window);

    update_button(event, scroll->button, window);
    if ((scroll->state == NONE || scroll->state == RELEASED)) {
        if (IS_HOVER(scroll->button) || IS_PRESSED(scroll->button))
            scroll->state = HOVER;
    } else if (is_active
        || IS_HOVER(scroll->button) || IS_PRESSED(scroll->button)) {
        scroll->state = HOVER;
    } else {
        scroll->state = RELEASED;
    }
}

void update_top_bar_status(top_bar_t *top_bar, sfEvent *event,
    sfRenderWindow *window)
{
    linked_list_t *actual = *top_bar->scrolls;
    menu_scrolling_t *scroll = NULL;

    while (actual != NULL) {
        scroll = actual->data;
        update_scroll(scroll, event, window);
        actual = actual->next;
    }
}
