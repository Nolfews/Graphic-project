/*
** EPITECH PROJECT, 2024
** theascencionofsorcererstower
** File description:
** main
*/

#include "toast.hpp"
#include <iostream>

Game *currentGame = nullptr;

int main(int ac, char **av)
{
    Game *game = new Game;

    (void)ac;
    (void)av;
    currentGame = game;
    game->run();
    return (0);
}
