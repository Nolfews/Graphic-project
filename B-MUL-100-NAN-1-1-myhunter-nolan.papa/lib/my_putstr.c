/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** displays, one-by-one, the characters of a string
*/

#include "../header.h"

void my_putstr(char const *str)
{
    int i;

    for (i = 0; *(str + i) != '\0'; i++) {
        my_putchar(*(str + i));
    }
}
