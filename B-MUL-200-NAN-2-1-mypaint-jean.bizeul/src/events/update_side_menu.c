/*
** EPITECH PROJECT, 2024
** update side menu
** File description:
** update side menu
*/

#include "../../include/main.h"

static void update_side_menu(menu_sidebar_t *menu, button_t *button,
    sfEvent *event, sfRenderWindow *window)
{
    update_button(event, button, window);
    if ((menu->state == NONE || menu->state == RELEASED)) {
        if (IS_HOVER(button) || IS_PRESSED(button))
            menu->state = HOVER;
    } else {
        menu->state = RELEASED;
    }
}

void update_side_menu_status(menu_sidebar_t *menu, sfEvent *event,
    sfRenderWindow *window)
{
    linked_list_t *actual = *menu->buttons;
    button_t *button = NULL;

    while (actual != NULL) {
        button = actual->data;
        update_side_menu(menu, button, event, window);
        actual = actual->next;
    }
}
