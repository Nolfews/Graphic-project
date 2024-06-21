/*
** EPITECH PROJECT, 2024
** BaptisteAndMoniqueAtTheParisSummerOlympics
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "blocks/platforms/effect/eOneMap.hpp"

EOneMap::EOneMap(sf::Vector2f position, const std::string &texture_path)
    : AbstractEffectPlatform(position, texture_path)
{}

EOneMap::EOneMap(const JsonObject *conf) : AbstractEffectPlatform(conf)
{}

void EOneMap::applyEffect()
{
    currentGame->getCurrentLevel()->reset();
}

bool EOneMap::hit(sf::Sprite *sprite)
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
            sf::Vector2f pos = {static_cast<float>(j), static_cast<float>(i)};
            if (pos.x < _position.x || pos.x > _position.x + simpleBlockSize)
                return false;
            float limit = simpleBlockSize - (simpleBlockSize - abs(pos.x - _position.x));
            if (pos.y < _position.y || pos.y > _position.y + simpleBlockSize || pos.y < _position.y + limit)
                return false;
                }
    }
    if (sprite->getPosition().x == currentGame->getPlayer1()->getPosition().x && sprite->getPosition().y == currentGame->getPlayer1()->getPosition().y)
        return true;
    applyEffect();
    return true;
}

EOneMap &EOneMap::operator=(const EOneMap &other)
{
    if (&other == this)
        return *this;
    AbstractEffectPlatform::operator=(other);
    return *this;
}
