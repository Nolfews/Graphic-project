/*
** EPITECH PROJECT, 2023
** my put unsigned int
** File description:
** put unsigned int
*/

#include "../header.h"

void my_put_nbr(int nb)
{
    if ( nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + 48);
}
