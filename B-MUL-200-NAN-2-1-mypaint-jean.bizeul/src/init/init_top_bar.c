/*
** EPITECH PROJECT, 2024
** paint
** File description:
** initializes the top bar
*/

#include "../../include/main.h"

static menu_scrolling_t *init_files_menu(textures_t *textures)
{
    menu_scrolling_t *menu = malloc(sizeof(menu_scrolling_t));

    menu->button = init_button(textures->files, (sfVector2f){0, 0},
        (sfVector2f){1, 1}, (sfIntRect){0, 0, 64, 32});
    menu->buttons = malloc(sizeof(linked_list_t *));
    *menu->buttons = NULL;
    menu->state = NONE;
    push_to_list(menu->buttons, init_button(textures->files,
        (sfVector2f){0, 32}, (sfVector2f){1, 1}, (sfIntRect){64, 0, 64, 32}));
    push_to_list(menu->buttons, init_button(textures->files,
        (sfVector2f){0, 64}, (sfVector2f){1, 1}, (sfIntRect){128, 0, 64, 32}));
    push_to_list(menu->buttons, init_button(textures->files,
        (sfVector2f){0, 96}, (sfVector2f){1, 1}, (sfIntRect){192, 0, 64, 32}));
    return menu;
}

static menu_scrolling_t *init_tools_menu(textures_t *textures)
{
    menu_scrolling_t *menu = malloc(sizeof(menu_scrolling_t));

    menu->button = init_button(textures->tools_buttons, (sfVector2f){64, 0},
        (sfVector2f){1, 1}, (sfIntRect){0, 0, 64, 32});
    menu->buttons = malloc(sizeof(linked_list_t *));
    *menu->buttons = NULL;
    menu->state = NONE;
    push_to_list(menu->buttons, init_button(textures->tools_buttons,
        (sfVector2f){64, 32}, (sfVector2f){1, 1},
        (sfIntRect){64, 0, 64, 32}));
    push_to_list(menu->buttons, init_button(textures->tools_buttons,
        (sfVector2f){64, 64}, (sfVector2f){1, 1},
        (sfIntRect){128, 0, 64, 32}));
    return menu;
}

static menu_scrolling_t *init_help_menu(textures_t *textures)
{
    menu_scrolling_t *menu = malloc(sizeof(menu_scrolling_t));

    menu->button = init_button(textures->help, (sfVector2f){128, 0},
        (sfVector2f){1, 1}, (sfIntRect){0, 0, 64, 32});
    menu->buttons = malloc(sizeof(linked_list_t *));
    *menu->buttons = NULL;
    menu->state = NONE;
    push_to_list(menu->buttons, init_button(textures->help,
        (sfVector2f){128, 32}, (sfVector2f){1, 1},
        (sfIntRect){64, 0, 64, 32}));
    push_to_list(menu->buttons, init_button(textures->help,
        (sfVector2f){128, 64}, (sfVector2f){1, 1},
        (sfIntRect){128, 0, 64, 32}));
    return menu;
}

static sfRectangleShape *create_rect(void)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (sfVector2f){1080, 32});
    sfRectangleShape_setFillColor(rect, sfBlack);
    sfRectangleShape_setOutlineColor(rect, (sfColor){225, 225, 225, 255});
    sfRectangleShape_setOutlineThickness(rect, 5);
    return rect;
}

static sfBool init_text(top_bar_t *top_bar)
{
    top_bar->text = sfText_create();
    top_bar->font = sfFont_createFromFile("data/Daydream.ttf");
    if (top_bar->font == NULL)
        return sfFalse;
    sfText_setFont(top_bar->text, top_bar->font);
    sfText_setColor(top_bar->text, sfBlack);
    sfText_setString(top_bar->text, "****Placeholder****\n");
    return sfTrue;
}

top_bar_t *init_top_bar(textures_t *textures)
{
    top_bar_t *top_bar = malloc(sizeof(top_bar_t));

    top_bar->rect = create_rect();
    top_bar->scrolls = malloc(sizeof(linked_list_t *));
    *top_bar->scrolls = NULL;
    push_to_list(top_bar->scrolls, init_files_menu(textures));
    push_to_list(top_bar->scrolls, init_tools_menu(textures));
    push_to_list(top_bar->scrolls, init_help_menu(textures));
    top_bar->save = NULL;
    top_bar->open = NULL;
    top_bar->about = NULL;
    top_bar->help = NULL;
    if (!init_text(top_bar))
        return NULL;
    init_buttons_functions_top_bar(top_bar);
    return top_bar;
}
