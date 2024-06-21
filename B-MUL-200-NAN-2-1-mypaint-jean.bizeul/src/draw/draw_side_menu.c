/*
** EPITECH PROJECT, 2024
** side menu
** File description:
** gestion des boutons du side menu
*/

#include "../../include/main.h"

static void display_side_menu(menu_sidebar_t *menu, sfRenderWindow *window)
{
    linked_list_t *actual = *menu->buttons;
    button_t *button = NULL;

    while (actual != NULL) {
        button = actual->data;
        draw_button(window, button);
        actual = actual->next;
    }
}

void draw_side_menu(paint_t *paint)
{
    menu_sidebar_t *side_menu = paint->side;
    linked_list_t *actual = *side_menu->buttons;

    while (actual != NULL) {
        display_side_menu(side_menu, paint->window);
        actual = actual->next;
    }
    sfRenderWindow_drawSprite(paint->window, paint->side->color, NULL);
}
