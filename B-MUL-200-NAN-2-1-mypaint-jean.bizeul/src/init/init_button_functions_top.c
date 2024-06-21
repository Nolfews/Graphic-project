/*
** EPITECH PROJECT, 2024
** paint
** File description:
** inits the functions related to the top bar's buttons
*/

#include "../../include/main.h"

void init_buttons_functions_files(menu_scrolling_t *scroll)
{
    linked_list_t *actual = *scroll->buttons;
    button_t *button = NULL;

    if (actual != NULL) {
        button = actual->data;
        button->is_click = &reset_layers;
        actual = actual->next;
    }
    if (actual != NULL) {
        button = actual->data;
        button->is_click = &open_file;
        actual = actual->next;
    }
    if (actual != NULL) {
        button = actual->data;
        button->is_click = &save_layers_as_file;
    }
}

void init_buttons_functions_tools(menu_scrolling_t *scroll)
{
    linked_list_t *actual = *scroll->buttons;
    button_t *button = NULL;

    if (actual != NULL) {
        button = actual->data;
        button->is_click = &set_tool_to_rubber;
        actual = actual->next;
    }
    if (actual != NULL) {
        button = actual->data;
        button->is_click = &set_tool_to_pencil;
    }
}

void init_buttons_functions_help(menu_scrolling_t *scroll)
{
    linked_list_t *actual = *scroll->buttons;
    button_t *button = NULL;

    if (actual != NULL) {
        button = actual->data;
        button->is_click = &display_help_window;
        actual = actual->next;
    }
    if (actual != NULL) {
        button = actual->data;
        button->is_click = &display_about_window;
    }
}

void init_buttons_functions_top_bar(top_bar_t *top_bar)
{
    linked_list_t *actual = *top_bar->scrolls;
    menu_scrolling_t *scroll = NULL;

    if (actual != NULL) {
        scroll = actual->data;
        init_buttons_functions_help(scroll);
        actual = actual->next;
    }
    if (actual != NULL) {
        scroll = actual->data;
        init_buttons_functions_tools(scroll);
        actual = actual->next;
    }
    if (actual != NULL) {
        scroll = actual->data;
        init_buttons_functions_files(scroll);
    }
}
