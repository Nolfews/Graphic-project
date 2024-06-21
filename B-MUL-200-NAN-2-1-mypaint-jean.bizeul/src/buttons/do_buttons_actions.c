/*
** EPITECH PROJECT, 2024
** paint
** File description:
** do buttons actions
*/

#include "../../include/main.h"

static void do_button_list_actions(linked_list_t *buttons, paint_t *paint)
{
    linked_list_t *actual = buttons;
    button_t *button = NULL;

    while (actual != NULL) {
        button = actual->data;
        if (IS_PRESSED(button))
            button->is_click(paint);
        actual = actual->next;
    }
}

static void do_top_buttons_actions(paint_t *paint)
{
    linked_list_t *actual = *paint->top->scrolls;
    menu_scrolling_t *scroll = NULL;

    while (actual != NULL) {
        scroll = actual->data;
        do_button_list_actions(*scroll->buttons, paint);
        actual = actual->next;
    }
}

void do_buttons_actions(paint_t *paint)
{
    do_top_buttons_actions(paint);
    do_button_list_actions(*paint->side->buttons, paint);
}
