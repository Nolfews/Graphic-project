/*
** EPITECH PROJECT, 2024
** paint
** File description:
** main file
*/

#include "../include/main.h"

int main(int argc, char const **argv)
{
    paint_t *paint = NULL;

    if (!parse_args(argc, argv))
        return 84;
    paint = init_paint_struct();
    if (paint == NULL)
        return 84;
    sfRenderWindow_setFramerateLimit(paint->window, 60);
    main_loop(paint);
    free(paint);
    return 0;
}
