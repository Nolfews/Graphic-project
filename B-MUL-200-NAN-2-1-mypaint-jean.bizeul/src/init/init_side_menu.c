/*
** EPITECH PROJECT, 2024
** init side menu
** File description:
** initialise le side menu
*/

#include "../../include/main.h"

void init_side_text(menu_sidebar_t *sidebar, paint_t *paint)
{
    sidebar->color = sfSprite_create();
    sfSprite_setTexture(sidebar->color, paint->textures->colors, sfFalse);
    sfSprite_setPosition(sidebar->color, (sfVector2f){765, 415});
    sfSprite_setScale(sidebar->color, (sfVector2f){0.35, 0.35});
}

void init_side_color(menu_sidebar_t *sidebar, paint_t *paint)
{
    sidebar->text = sfText_create();
    sfText_setFont(sidebar->text, paint->top->font);
    sfText_setColor(sidebar->text, sfBlack);
    sfText_setCharacterSize(sidebar->text, 20);
    sfText_setString(sidebar->text, "Outil :\n\n\n\nSize :\n\n\n\n\nShape :");
}

menu_sidebar_t *init_side_menu(paint_t *paint)
{
    menu_sidebar_t *sidebar = malloc(sizeof(menu_sidebar_t));
    linked_list_t **linked_grid = malloc(sizeof(linked_list_t *));

    *linked_grid = NULL;
    push_to_list(linked_grid, init_button(paint->textures->size,
    (sfVector2f){800, 200}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 64, 32}));
    push_to_list(linked_grid, init_button(paint->textures->size,
    (sfVector2f){900, 200}, (sfVector2f){1, 1}, (sfIntRect){64, 0, 64, 32}));
    push_to_list(linked_grid, init_button(paint->textures->shape,
    (sfVector2f){800, 350}, (sfVector2f){1, 1}, (sfIntRect){0, 0, 64, 32}));
    push_to_list(linked_grid, init_button(paint->textures->shape,
    (sfVector2f){900, 350}, (sfVector2f){1, 1}, (sfIntRect){64, 0, 64, 32}));
    sidebar->buttons = linked_grid;
    init_buttons_functions_side_bar(sidebar);
    init_side_color(sidebar, paint);
    init_side_text(sidebar, paint);
    return sidebar;
}
