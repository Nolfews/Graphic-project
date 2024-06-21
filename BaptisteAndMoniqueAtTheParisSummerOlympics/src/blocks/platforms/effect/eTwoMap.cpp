/*
** EPITECH PROJECT, 2024
** BaptisteAndMoniqueAtTheParisSummerOlympics
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "blocks/platforms/effect/eTwoMap.hpp"

ETwoMap::ETwoMap(sf::Vector2f position, const std::string &texture_path)
    : AbstractEffectPlatform(position, texture_path)
{}

ETwoMap::ETwoMap(const JsonObject *conf) : AbstractEffectPlatform(conf)
{}

void ETwoMap::applyEffect()
{
    currentGame->getCurrentLevel()->reset();
}

bool ETwoMap::hit(sf::Sprite *sprite)
{
    for (std::size_t i = sprite->getGlobalBounds().top; i < sprite->getGlobalBounds().top + sprite->getGlobalBounds().height; i++) {
        for (std::size_t j = sprite->getGlobalBounds().left; j < sprite->getGlobalBounds().left + sprite->getGlobalBounds().width; j++) {
            if (_sprite.getGlobalBounds().contains(j, i)) {
                if (sprite->getPosition().x == currentGame->getPlayer1()->getPosition().x && sprite->getPosition().y == currentGame->getPlayer1()->getPosition().y)
                    return true;
                applyEffect();
                return true;
            }
        }
    }
    return false;
}

ETwoMap &ETwoMap::operator=(const ETwoMap &other)
{
    if (&other == this)
        return *this;
    AbstractEffectPlatform::operator=(other);
    return *this;
}
