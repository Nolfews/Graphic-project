/*
** EPITECH PROJECT, 2024
** BaptisteAndMoniqueAtTheParisSummerOlympics
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "blocks/platforms/effect/AbstractEffectPlatform.hpp"
#include "Game.hpp"

class PTwoMap : public AbstractEffectPlatform {
   public:
    PTwoMap() = default;
    PTwoMap(sf::Vector2f position, const std::string &texture_path);
    PTwoMap(const PTwoMap &other) = default;
    PTwoMap(const JsonObject *conf);
    ~PTwoMap() = default;
    void applyEffect();
    bool hit(sf::Sprite *sprite) override;

    PTwoMap &operator=(const PTwoMap &other);
};
