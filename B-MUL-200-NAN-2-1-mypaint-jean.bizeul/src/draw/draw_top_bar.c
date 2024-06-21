/*
** EPITECH PROJECT, 2024
** paint
** File description:
** draws the top bar
*/

#include "../../include/main.h"

static void display_scrolling(menu_scrolling_t *scroll, sfRenderWindow *window)
{
    linked_list_t *actual = *scroll->buttons;
    button_t *button = NULL;

    draw_button(window, scroll->button);
    if (scroll->state == HOVER) {
        while (actual != NULL) {
            button = actual->data;
            draw_button(window, button);
            actual = actual->next;
        }
    }
}

void draw_top_bar(paint_t *paint)
{
    linked_list_t *actual = *paint->top->scrolls;
    menu_scrolling_t *scrolls = NULL;

    sfRenderWindow_drawRectangleShape(paint->window, paint->top->rect, NULL);
    while (actual != NULL) {
        scrolls = actual->data;
        display_scrolling(scrolls, paint->window);
        actual = actual->next;
    }
}
