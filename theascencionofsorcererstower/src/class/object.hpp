/*
** EPITECH PROJECT, 2024
** theascencionofsorcererstower
** File description:
** object
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class AObject {
public:
    AObject();
    AObject(std::string path, sf::IntRect ar, sf::IntRect hb, bool collisions);
    ~AObject();

    // setter
    void setSprite(sf::Sprite sprite);
    void setTexture(sf::Texture texture);
    void setAnimRect(sf::IntRect animrect);
    void setHitBox(sf::IntRect hitbox);
    void setCollisions(bool collisions);

    // getter
    sf::Sprite *getSprite(void);
    sf::Texture *getTexture(void);
    sf::IntRect *getAnimRect(void);
    sf::IntRect *getHitBox(void);
    bool getCollisions(void);

protected:
    //Sprite
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::IntRect _animrect;

    //Hitbox
    sf::IntRect _hitbox;
    bool _collisions;
};
