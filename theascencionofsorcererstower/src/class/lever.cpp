/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** lever
*/

#include "lever.hpp"
#include "game.hpp"

Lever::Lever() : AObject("assets/lever/lever(275x170).png", (sf::IntRect){0, 0, 275, 170}, (sf::IntRect){70, 100, 135, 70}, false) {}

Lever::Lever(scene_lever_t dest, sf::Vector2f pos, sf::Vector2f objectPos)
{
    _dest = dest;
    _collisions = false;
    _objectPos = objectPos;
    _animrect = (sf::IntRect){0, 0, 275, 170};
    _hitbox = (sf::IntRect){70, 100, 135, 70};
    _texture.loadFromFile("assets/lever/lever(275x170).png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_animrect.width / 2, _animrect.height);
    _sprite.setPosition(pos);
    _leverTexture.loadFromFile("assets/lever/lever(275x170).png", _animrect);
    _lever.setTexture(_leverTexture);
    _lever.setTextureRect(_animrect);
    _lever.setOrigin(_animrect.width / 2, _animrect.height);
    _lever.setPosition(pos);
    _objectTexture.loadFromFile("assets/lever/leverDoor(32x96).png", _animrect);
    _object.setTexture(_objectTexture);
    _object.setTextureRect(_animrect);
    _object.setOrigin(_animrect.width / 2, _animrect.height);
    _object.setPosition(pos);
}

Lever::~Lever()
{
}

void Lever::openLever(void)
{
    _animclock.restart();
    while (_animclock.getElapsedTime().asMilliseconds() > 750);
    for (int i = 0; i < 3;) {
        if (_animclock.getElapsedTime().asMilliseconds() > 750) {
            i++;
            _animrect.top += _animrect.height;
            _object.setPosition((sf::Vector2f) {_objectPos.x, _objectPos.y - 24});
            _sprite.setTextureRect(_animrect);
            _lever.setTextureRect(_animrect);
            _animclock.restart();
        }
        currentGame->draw();
    }
}

void Lever::closeLever(void)
{
    _animclock.restart();
    while (_animclock.getElapsedTime().asMilliseconds() > 750);
    for (int i = 0; i < 3;) {
        if (_animclock.getElapsedTime().asMilliseconds() > 750) {
            i++;
            _animrect.top -= _animrect.height;
            _object.setPosition((sf::Vector2f) {_objectPos.x, _objectPos.y + 24});
            _sprite.setTextureRect(_animrect);
            _lever.setTextureRect(_animrect);
            _animclock.restart();
        }
        currentGame->draw();
    }

}

bool Lever::isOnLever(sf::Vector2f pos, bool isonground)
{
    if (pos.x > _sprite.getPosition().x - _hitbox.width / 2 && pos.x < _sprite.getPosition().x + _hitbox.width / 2
        && pos.y > _sprite.getPosition().y - _hitbox.height / 2 && pos.y < _sprite.getPosition().y + _hitbox.height / 2
        && isonground)
            return true;
        return false;
}

void Lever::setLeverSprite(sf::Sprite lever)
{
    _lever = lever;
}

void Lever::setObjectSprite(sf::Sprite object)
{
    _object = object;
}

void Lever::setLeverTexture(sf::Texture leverTexture)
{
    _leverTexture = leverTexture;
}

void Lever::setObjectTexture(sf::Texture objectTexture)
{
    _objectTexture = objectTexture;
}

void Lever::setAnimClock(sf::Clock animclock)
{
    _animclock = animclock;
}

void Lever::setLeverPos(sf::Vector2f leverPos)
{
    _leverPos = leverPos;
}

void Lever::setObjectPos(sf::Vector2f objectPos)
{
    _objectPos = objectPos;
}

void Lever::setDest(scene_lever_t dest)
{
    _dest = dest;
}


sf::Sprite *Lever::getLeverSprite(void)
{
    return &_lever;
}

sf::Sprite *Lever::getObjectSprite(void)
{
    return &_object;
}

sf::Texture *Lever::getLeverTexture(void)
{
    return &_leverTexture;
}

sf::Texture *Lever::getObjectTexture(void)
{
    return &_objectTexture;
}

sf::Clock *Lever::getAnimClock(void)
{
    return &_animclock;
}

sf::Vector2f Lever::getLeverPos(void)
{
    return _leverPos;
}

sf::Vector2f Lever::getObjectPos(void)
{
    return _objectPos;
}

scene_lever_t Lever::getDest(void)
{
    return _dest;
}
