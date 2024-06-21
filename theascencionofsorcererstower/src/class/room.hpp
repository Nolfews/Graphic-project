/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** room
*/

#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>
#include "door.hpp"

class Room {
public:
    Room(scene_t room);
    ~Room();

    bool isOnImage(sf::Vector2f pos);

    //setter
    void setBackSprite(sf::Sprite backsprite);
    void setBackTexture(sf::Texture backtexture);
    void setForeSprite(sf::Sprite foresprite);
    void setForeTexture(sf::Texture foretexture);
    void setCollisions(sf::Image collisions);
    void addDoor(Door door, scene_t dest);
    void setGravity(float gravity);

    //getter
    sf::Sprite *getBackSprite(void);
    sf::Texture *getBackTexture(void);
    sf::Sprite *getForeSprite(void);
    sf::Texture *getForeTexture(void);
    sf::Image *getCollisions(void);
    std::unordered_map<scene_t, Door> getDoors(void);
    Door *getDoorByDest(scene_t dest);
    float getGravity(void);

private:
    sf::Sprite _backsprite;
    sf::Texture _backtexture;
    sf::Sprite _foresprite;
    sf::Texture _foretexture;
    sf::Image _collisions;
    std::unordered_map<scene_t, Door> _doors;
    float _gravity;
};
