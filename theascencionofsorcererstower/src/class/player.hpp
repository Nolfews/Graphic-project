/*
** EPITECH PROJECT, 2024
** theascencionofsorcererstower
** File description:
** player
*/

#pragma once

#include <SFML/Graphics.hpp>

#define SPEED 3

typedef enum dir {
    IDDLE = 0,
    RIGHT,
    LEFT
}dir_t;

class Player {
public:
    Player();
    ~Player();

    // Methods
    void update(void);
    void animPlayer(void);
    void movePlayer(void);

    // Setters
    void setMaxHealth(int max);
    void setHealth(int health);
    void setDamage(int damage);
    void setVelocity(float x, float y);

    void setDirection(dir_t direction);
    void setIddleSprite(sf::Sprite sprite);
    void setIddleTexture(sf::Texture texture);
    void setIddleAnimRect(sf::IntRect rect);

    void setAtkHitbox(sf::IntRect rect);
    void setAtkClock(sf::Clock clock);
    void setAtkTexture(sf::Texture texture);
    void setAtkSprite(sf::Sprite sprite);
    void setPosition(sf::Vector2f position);
    void setGround(bool ground);
    void setOrientation(void);
    void setCrouching(bool crouch);
    void setDelta(float delta);

    sf::Sprite *getPlayerSprite(void);
    sf::Texture getPlayerTexture(void);
    sf::IntRect *getPlayerRect(void);
    sf::IntRect getPlayerRectLocal(void);
    sf::Clock *getAnimClock(void);
    float getAnimTime(void);
    sf::Vector2f *getVelocity(void);
    sf::Clock *getMovementClock(void);
    sf::Vector2f getPosition(void);
    bool getCrouching(void);
    bool getGround(void);
    float getDelta(void);

private:

    //Iddle
    sf::Sprite iddle_sprite;
    sf::Texture iddle_texture;
    sf::IntRect iddle_anim_rect;

    // Right
    sf::Sprite run_sprite;
    sf::Texture run_texture;

    // Fall
    sf::Sprite fall_sprite;
    sf::Texture fall_texture;

    // Jump
    sf::Sprite jump_sprite;
    sf::Texture jump_texture;

    //Movement
    dir_t _direction;
    sf::Clock _mov_clock;
    float _deltaTime;
    sf::Vector2f _position;
    bool onGround;
    bool crouching;

    //Animation
    sf::Clock _clock;

    //Attack
    sf::IntRect _attack_hitbox;
    sf::Clock _attack_clock;
    sf::Texture _attack_texture;
    sf::Sprite _attack_sprite;

    //Stats
    int _max_health;
    int _health;
    int _damage;
    sf::Vector2f _velocity;
};
