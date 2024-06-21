/*
** EPITECH PROJECT, 2024
** paint
** File description:
** events management main file
*/

#include "../../include/main.h"

static sfBool is_scroll_clicked(linked_list_t *scroll)
{
    linked_list_t *actual = scroll;
    button_t *button = NULL;

    while (actual != NULL) {
        button = actual->data;
        if (IS_PRESSED(button))
            return sfTrue;
        actual = actual->next;
    }
    return sfFalse;
}

static sfBool is_top_bar_clicked(top_bar_t *top_bar)
{
    linked_list_t *actual = *top_bar->scrolls;
    menu_scrolling_t *scroll = NULL;

    while (actual != NULL) {
        scroll = actual->data;
        if (is_scroll_clicked(*scroll->buttons))
            return sfTrue;
        actual = actual->next;
    }
    return sfFalse;
}

int manage_events(paint_t *paint)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(paint->window, &event)) {
        if (event.type == sfEvtClosed)
            return 0;
        if (event.type == sfEvtMouseButtonPressed)
            event_color(&event, paint);
        update_top_bar_status(paint->top, &event, paint->window);
        update_side_menu_status(paint->side, &event, paint->window);
        if (!is_top_bar_clicked(paint->top))
            update_board(&event, paint);
    }
    return 1;
}
