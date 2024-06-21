/*
** EPITECH PROJECT, 2024
** paint
** File description:
** initializes textures
*/

#include "../../include/main.h"

textures_t *init_textures(void)
{
    textures_t *textures = malloc(sizeof(textures_t));

    textures->files = sfTexture_createFromFile("data/files_buttons.png",
        NULL);
    textures->tools_buttons = sfTexture_createFromFile(
        "data/tools_buttons.png", NULL);
    textures->help = sfTexture_createFromFile("data/help_buttons.png", NULL);
    textures->size = sfTexture_createFromFile("data/size_buttons.png", NULL);
    textures->shape = sfTexture_createFromFile("data/shape_buttons.png", NULL);
    textures->colors = sfTexture_createFromFile("data/color_circle.png", NULL);
    if (textures->files == NULL || textures->tools_buttons == NULL ||
        textures->size == NULL || textures->shape == NULL
        || textures->colors == NULL) {
        write(2, "An error occured while trying to create textures\n", 49);
        return NULL;
    }
    return textures;
}
