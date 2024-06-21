/*
** EPITECH PROJECT, 2024
** paint
** File description:
** window management
*/

#include "../include/main.h"

sfRenderWindow *create_renderwindow(int width, int height, sfWindowStyle style,
    char *name)
{
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    return sfRenderWindow_create(video_mode, name, style, NULL);
}
