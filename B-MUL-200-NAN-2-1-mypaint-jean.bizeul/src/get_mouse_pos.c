/*
** EPITECH PROJECT, 2024
** paint
** File description:
** function used to get the mouse's position without considering
*/

#include "../include/main.h"

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2i win_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = sfRenderWindow_mapPixelToCoords(window, win_pos, view);

    return pos;
}
