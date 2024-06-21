/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** door
*/

#include "door.hpp"
#include "game.hpp"

Door::Door(): AObject("assets/idle_door.png", (sf::IntRect){0, 0, 46, 56}, (sf::IntRect){7, 2, 32, 42}, false) {}

Door::Door(scene_t dest, sf::Vector2f pos, sf::Vector2f destpos)
{
    _dest = dest;
    _collisions = false;
    _destpos = destpos;
    _animrect = (sf::IntRect){0, 0, 46, 56};
    _hitbox = (sf::IntRect){7, 2, 32, 42};
    _texture.loadFromFile("assets/idle_door.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_animrect.width / 2, _animrect.height);
    _sprite.setPosition(pos);
    _intexture.loadFromFile("assets/opening(46x56).png", _animrect);
    _insprite.setTexture(_intexture);
    _insprite.setTextureRect(_animrect);
    _insprite.setOrigin(_animrect.width / 2, _animrect.height);
    _insprite.setPosition(pos);
    _outtexture.loadFromFile("assets/closing(46x56).png", _animrect);
    _outsprite.setTexture(_outtexture);
    _outsprite.setTextureRect(_animrect);
    _outsprite.setOrigin(_animrect.width / 2, _animrect.height);
    _outsprite.setPosition(pos);
}

Door::~Door()
{
}

void Door::openDoor(void)
{
    _animclock.restart();
    while (_animclock.getElapsedTime().asMilliseconds() > 750);
    for (int i = 0; i < 4;) {
        if (_animclock.getElapsedTime().asMilliseconds() > 750) {
            i++;
            _animrect.left += _animrect.width;
            _sprite.setTextureRect(_animrect);
            _insprite.setTextureRect(_animrect);
            _animclock.restart();
        }
        currentGame->draw();
    }
    _animrect.left = 0;
}

void Door::closeDoor(void)
{
    _animclock.restart();
    while (_animclock.getElapsedTime().asMilliseconds() > 750);
    for (int i = 0; i < 2;) {
        if (_animclock.getElapsedTime().asMilliseconds() > 750) {
            i++;
            _animrect.left += _animrect.width;
            _insprite.setTextureRect(_animrect);
            _animclock.restart();
        }
        currentGame->draw();
    }
    _animrect.left = 0;
}

bool Door::isOnDoor(sf::Vector2f pos, bool isonground)
{
    if (pos.x > _sprite.getPosition().x - _hitbox.width / 2 && pos.x < _sprite.getPosition().x + _hitbox.width / 2
    && pos.y > _sprite.getPosition().y - _hitbox.height / 2 && pos.y < _sprite.getPosition().y + _hitbox.height / 2
    && isonground)
        return (true);
    return (false);
}

void Door::setInSprite(sf::Sprite insprite)
{
    _insprite = insprite;
}

void Door::setOutSprite(sf::Sprite outsprite)
{
    _outsprite = outsprite;
}

void Door::setInTexture(sf::Texture intexture)
{
    _intexture = intexture;
}

void Door::setOutTexture(sf::Texture outtexture)
{
    _outtexture = outtexture;
}

void Door::setAnimClock(sf::Clock animclock)
{
    _animclock = animclock;
}

void Door::setDestPos(sf::Vector2f destpos)
{
    _destpos = destpos;
}

void Door::setDest(scene_t dest)
{
    _dest = dest;
}

sf::Sprite &Door::getInSprite(void)
{
    return (_insprite);
}

sf::Sprite &Door::getOutSprite(void)
{
    return (_outsprite);
}

sf::Texture &Door::getInTexture(void)
{
    return (_intexture);
}

sf::Texture &Door::getOutTexture(void)
{
    return (_outtexture);
}

sf::Clock *Door::getAnimClock(void)
{
    return (&_animclock);
}

sf::Vector2f Door::getDestPos(void)
{
    return (_destpos);
}

scene_t Door::getDest(void)
{
    return (_dest);
}
