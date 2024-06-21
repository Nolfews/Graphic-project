/*
** EPITECH PROJECT, 2024
** BaptisteAndMoniqueAtTheParisSummerOlympics
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "blocks/platforms/tTwoMap.hpp"
#include "Game.hpp"
#include <cmath>
#include <iostream>

TTwoMap::TTwoMap(sf::Vector2f position, const std::string &texture_path)
    : AbstractPlatform(position, texture_path)
{}

TTwoMap::TTwoMap(const JsonObject *json) : AbstractPlatform(json)
{}

bool TTwoMap::hit(sf::Sprite *sprite)
{
    float biggerX = 0.0f;
    AbstractBlock **blocks = currentGame->getCurrentLevel()->getBlocks();
    for (int i = 0; i < currentGame->getCurrentLevel()->getNbBlocks(); i++) {
        if (blocks[i]->getPosition().x > biggerX)
            biggerX = blocks[i]->getPosition().x;
    }
    float simpleBlockSize = currentGame->getWindow().getSize().x / biggerX;
    for (std::size_t i = sprite->getGlobalBounds().top; i < sprite->getGlobalBounds().top + sprite->getGlobalBounds().height; i++) {
        for (std::size_t j = sprite->getGlobalBounds().left; j < sprite->getGlobalBounds().left + sprite->getGlobalBounds().width; j++) {
            sf::Vector2f position = {static_cast<float>(j), static_cast<float>(i)};
            if (position.x < _position.x || position.x > _position.x + simpleBlockSize)
                return true;
            float limit = simpleBlockSize - (simpleBlockSize - abs(position.x - _position.x));
            if (position.y < _position.y || position.y > _position.y + simpleBlockSize || position.y < _position.y + limit)
                return true;
        }
    }
    return false;
}

TTwoMap &TTwoMap::operator=(const TTwoMap &other)
{
    if (&other == this)
        return *this;
    AbstractPlatform::operator=(other);
    return *this;
}
