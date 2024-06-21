/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** door
*/

#pragma once

#include "object.hpp"
#include "SFML/Graphics.hpp"

typedef enum scene {
    MENU = 0,
    WALK,
    JUMP,
    CROUCH,
    INTERACT,
    FIGHT,
    SHOP,
    CHALLENGE
} scene_t;

class Game;

class Door : public AObject {
public:
    Door();
    Door(scene_t dest, sf::Vector2f pos, sf::Vector2f destpos);
    ~Door();

    void openDoor(void);
    void closeDoor(void);
    bool isOnDoor(sf::Vector2f pos, bool isonground);

    // setter
    void setInSprite(sf::Sprite insprite);
    void setOutSprite(sf::Sprite outsprite);
    void setInTexture(sf::Texture intexture);
    void setOutTexture(sf::Texture outtexture);
    void setAnimClock(sf::Clock animclock);
    void setDestPos(sf::Vector2f destpos);
    void setDest(scene_t dest);

    // getter
    sf::Sprite &getInSprite(void);
    sf::Sprite &getOutSprite(void);
    sf::Texture &getInTexture(void);
    sf::Texture &getOutTexture(void);
    sf::Clock *getAnimClock(void);
    sf::Vector2f getDestPos(void);
    scene_t getDest(void);

private:
    sf::Sprite _insprite;
    sf::Sprite _outsprite;
    sf::Texture _intexture;
    sf::Texture _outtexture;
    sf::Clock _animclock;
    sf::Vector2f _destpos;
    scene_t _dest;
    bool _open;
};
