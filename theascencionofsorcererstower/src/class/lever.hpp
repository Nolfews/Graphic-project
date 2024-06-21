/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** lever
*/

#pragma once

#include "object.hpp"
#include "SFML/Graphics.hpp"

typedef enum scene_lever {
    INTERACT_LEVER = 4,
} scene_lever_t;

class Game;

class Lever : public AObject {
public:
    Lever();
    Lever(scene_lever_t dest, sf::Vector2f pos, sf::Vector2f objectPos);
    ~Lever();

    void openLever(void);
    void closeLever(void);
    bool isOnLever(sf::Vector2f pos, bool isonground);

    // setter
    void setLeverSprite(sf::Sprite lever);
    void setObjectSprite(sf::Sprite object);
    void setLeverTexture(sf::Texture leverTexture);
    void setObjectTexture(sf::Texture objectTexture);
    void setAnimClock(sf::Clock animclock);
    void setLeverPos(sf::Vector2f leverPos);
    void setObjectPos(sf::Vector2f objectPos);
    void setDest(scene_lever_t dest);

    // getter
    sf::Sprite *getLeverSprite(void);
    sf::Sprite *getObjectSprite(void);
    sf::Texture *getLeverTexture(void);
    sf::Texture *getObjectTexture(void);
    sf::Clock *getAnimClock(void);
    sf::Vector2f getLeverPos(void);
    sf::Vector2f getObjectPos(void);
    scene_lever_t getDest(void);

private:
    sf::Sprite _lever;
    sf::Sprite _object;
    sf::Texture _leverTexture;
    sf::Texture _objectTexture;
    sf::Clock _animclock;
    sf::Vector2f _leverPos;
    sf::Vector2f _objectPos;
    scene_lever_t _dest;
    bool _open;
};
