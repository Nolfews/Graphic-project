/*
** EPITECH PROJECT, 2024
** paint
** File description:
** free / destroy everything
*/

#include "../include/main.h"

static void free_board(board_t *board)
{
    delete_all_layers(board->end, board->begin);
    free(board->begin);
    free(board->end);
    sfRectangleShape_destroy(board->backgr);
    free(board);
}

static void free_side_bar(menu_sidebar_t *side_bar)
{
    linked_list_t *actual = *side_bar->buttons;
    linked_list_t *next = NULL;
    button_t *button = NULL;

    while (actual != NULL) {
        button = actual->data;
        sfSprite_destroy(button->sprite);
        free(button);
        next = actual->next;
        free(actual);
        actual = next;
    }
    free(side_bar->buttons);
    sfSprite_destroy(side_bar->color);
    free(side_bar);
}

static void free_scrolling_menu(menu_scrolling_t *scroll)
{
    linked_list_t *actual = *scroll->buttons;
    linked_list_t *next = NULL;
    button_t *button = NULL;

    while (actual != NULL) {
        next = actual->next;
        button = actual->data;
        sfSprite_destroy(button->sprite);
        free(button);
        free(actual);
        actual = next;
    }
    free(scroll);
}

static void free_top_bar(top_bar_t *top_bar)
{
    linked_list_t *actual = *top_bar->scrolls;
    linked_list_t *next = NULL;
    menu_scrolling_t *scroll = NULL;

    while (actual != NULL) {
        next = actual->next;
        scroll = actual->data;
        free_scrolling_menu(scroll);
        free(actual);
        actual = next;
    }
    free(top_bar->scrolls);
    sfRectangleShape_destroy(top_bar->rect);
    sfText_destroy(top_bar->text);
    sfFont_destroy(top_bar->font);
    free(top_bar);
}

static void free_textures(textures_t *textures)
{
    sfTexture_destroy(textures->colors);
    sfTexture_destroy(textures->files);
    sfTexture_destroy(textures->help);
    sfTexture_destroy(textures->shape);
    sfTexture_destroy(textures->size);
    sfTexture_destroy(textures->tools_buttons);
    free(textures);
}

void free_paint_struct(paint_t *paint)
{
    free_board(paint->draw);
    free_side_bar(paint->side);
    free_top_bar(paint->top);
    free_textures(paint->textures);
    sfRenderWindow_close(paint->window);
    sfRenderWindow_destroy(paint->window);
    free(paint);
}
