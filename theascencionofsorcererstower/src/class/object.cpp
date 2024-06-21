/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** object
*/

#include "object.hpp"

AObject::AObject()
{
}

AObject::AObject(std::string path, sf::IntRect ar, sf::IntRect hb, bool col)
{
    _animrect = ar;
    _hitbox = hb;
    _texture.loadFromFile(path, ar);
    _sprite.setTexture(_texture);
    _collisions = col;
}

AObject::~AObject()
{
}

void AObject::setSprite(sf::Sprite sprite)
{
    _sprite = sprite;
}

void AObject::setTexture(sf::Texture texture)
{
    _texture = texture;
}

void AObject::setAnimRect(sf::IntRect animrect)
{
    _animrect = animrect;
}

void AObject::setHitBox(sf::IntRect hitbox)
{
    _hitbox = hitbox;
}

void AObject::setCollisions(bool collisions)
{
    _collisions = collisions;
}

sf::Sprite *AObject::getSprite(void)
{
    return (&_sprite);
}

sf::Texture *AObject::getTexture(void)
{
    return (&_texture);
}

sf::IntRect *AObject::getAnimRect(void)
{
    return (&_animrect);
}

sf::IntRect *AObject::getHitBox(void)
{
    return (&_hitbox);
}

bool AObject::getCollisions(void)
{
    return (_collisions);
}
