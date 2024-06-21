/*
** EPITECH PROJECT, 2024
** paint
** File description:
** side bar button's functions attribution
*/

#include "../../include/main.h"

static void init_functions_shape(linked_list_t **list)
{
    linked_list_t *actual = *list;
    button_t *button = NULL;

    if (actual != NULL) {
        button = actual->data;
        button->is_click = &set_shape_circle;
        actual = actual->next;
    }
    if (actual != NULL) {
        button = actual->data;
        button->is_click = &set_shape_square;
        actual = actual->next;
    }
    *list = actual;
}

static void init_functions_size(linked_list_t **list)
{
    linked_list_t *actual = *list;
    button_t *button = NULL;

    if (actual != NULL) {
        button = actual->data;
        button->is_click = &increase_size;
        actual = actual->next;
    }
    if (actual != NULL) {
        button = actual->data;
        button->is_click = &decrease_size;
    }
}

void init_buttons_functions_side_bar(menu_sidebar_t *sidebar)
{
    linked_list_t *actual = *sidebar->buttons;

    init_functions_shape(&actual);
    init_functions_size(&actual);
}
