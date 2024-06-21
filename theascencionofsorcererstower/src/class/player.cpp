/*
** EPITECH PROJECT, 2024
** The ascencion of the sorcerer's tower
** File description:
** player
*/

#include "player.hpp"
#include "game.hpp"

#define MAX_FALL_SPEED 1

Player::Player()
{
    setMaxHealth(100);
    setHealth(100);
    setDamage(10);
    setVelocity(0, 0);
    setDirection(IDDLE);
    setIddleAnimRect((sf::IntRect){0, 0, 45, 28});
    _clock = sf::Clock();
    _clock.restart();
    _mov_clock = sf::Clock();
    _mov_clock.restart();
    setPosition((sf::Vector2f){50, -50});
    iddle_texture.loadFromFile("assets/player/Idle(45x28).png");
    iddle_sprite.setTexture(iddle_texture, true);
    iddle_sprite.setTextureRect(iddle_anim_rect);
    run_texture.loadFromFile("assets/player/Right(45x28).png");
    run_sprite.setTexture(run_texture);
    run_sprite.setTextureRect(iddle_anim_rect);
    fall_texture.loadFromFile("assets/player/Fall(45x28).png");
    fall_sprite.setTexture(fall_texture);
    fall_sprite.setTextureRect(iddle_anim_rect);
    jump_texture.loadFromFile("assets/player/Jump(45x28).png");
    jump_sprite.setTexture(jump_texture);
    jump_sprite.setTextureRect(iddle_anim_rect);
    iddle_sprite.setOrigin((sf::Vector2f){22.5, 28});
    run_sprite.setOrigin((sf::Vector2f){22.5, 28});
    fall_sprite.setOrigin((sf::Vector2f){22.5, 28});
    jump_sprite.setOrigin((sf::Vector2f){22.5, 28});
    _deltaTime = 0;
}

Player::~Player()
{
}

void Player::setOrientation(void)
{
    if (_velocity.x >= 0) {
        fall_sprite.setScale((sf::Vector2f){1, 1});
        jump_sprite.setScale((sf::Vector2f){1, 1});
        iddle_sprite.setScale((sf::Vector2f){1, 1});
        run_sprite.setScale((sf::Vector2f){1, 1});
    } else {
        fall_sprite.setScale((sf::Vector2f){-1, 1});
        jump_sprite.setScale((sf::Vector2f){-1, 1});
        iddle_sprite.setScale((sf::Vector2f){-1, 1});
        run_sprite.setScale((sf::Vector2f){-1, 1});
    }
}

sf::Sprite *Player::getPlayerSprite(void)
{
    setOrientation();
    if (onGround == false) {
        if (_velocity.y > 0)
            return (&fall_sprite);
        return (&jump_sprite);
    }
    if (_velocity.x != 0)
        return (&run_sprite);
    return (&iddle_sprite);
}

sf::Texture Player::getPlayerTexture(void)
{
    if (onGround == false) {
        if (_velocity.y > 0)
            return (fall_texture);
        return (jump_texture);
    }
    if (_velocity.x != 0)
        return (run_texture);
    return (iddle_texture);
}

void Player::setMaxHealth(int max)
{
    _max_health = max;
}

void Player::setHealth(int health)
{
    _health = health;
}

void Player::setDamage(int damage)
{
    _damage = damage;
}

void Player::setVelocity(float x, float y)
{
    _velocity = (sf::Vector2f){x, y};
}

void Player::setDirection(dir_t direction)
{
    _direction = direction;
}

void Player::setIddleSprite(sf::Sprite sprite)
{
    iddle_sprite = sprite;
}

void Player::setIddleTexture(sf::Texture texture)
{
    iddle_texture = texture;
}

void Player::setIddleAnimRect(sf::IntRect rect)
{
    iddle_anim_rect = rect;
}

void Player::setAtkHitbox(sf::IntRect rect)
{
    _attack_hitbox = rect;
}

void Player::setAtkClock(sf::Clock clock)
{
    _attack_clock = clock;
}

void Player::setAtkTexture(sf::Texture texture)
{
    _attack_texture = texture;
}

void Player::setAtkSprite(sf::Sprite sprite)
{
    _attack_sprite = sprite;
}

void Player::setPosition(sf::Vector2f position)
{
    _position = position;
    iddle_sprite.setPosition(_position);
    run_sprite.setPosition(_position);
    fall_sprite.setPosition(_position);
    jump_sprite.setPosition(_position);
}

sf::IntRect *Player::getPlayerRect(void)
{
    return &iddle_anim_rect;
}

sf::IntRect Player::getPlayerRectLocal(void)
{
    return iddle_anim_rect;
}

sf::Clock *Player::getAnimClock(void)
{
    return &_clock;
}

float Player::getAnimTime(void)
{
    return 75;
}

sf::Vector2f *Player::getVelocity(void)
{
    return &_velocity;
}

sf::Clock *Player::getMovementClock(void)
{
    return &_mov_clock;
}

sf::Vector2f Player::getPosition(void)
{
    return _position;
}

void Player::setGround(bool ground)
{
    onGround = ground;
}

bool Player::getGround(void)
{
    return (onGround);
}

bool Player::getCrouching(void)
{
    return (crouching);
}

void Player::setCrouching(bool crouch)
{
    crouching = crouch;
}

void Player::setDelta(float delta)
{
    _deltaTime = delta;
}

float Player::getDelta(void)
{
    return _deltaTime;
}

void Player::update(void)
{
    animPlayer();
    movePlayer();
}

void Player::animPlayer(void)
{
    float time = getAnimClock()->getElapsedTime().asMilliseconds();
    sf::IntRect *rect = getPlayerRect();

    if (time > getAnimTime()) {
        getAnimClock()->restart();
        rect->left += rect->width;
        if (rect->left >= (int)getPlayerTexture().getSize().x)
            rect->left = 0;
    }
    getPlayerSprite()->setTextureRect(*rect);
}

void Player::movePlayer(void)
{
    float time = getMovementClock()->getElapsedTime().asMilliseconds();
    float deltaTime = getDelta();
    sf::Vector2f *velocity = getVelocity();
    sf::Vector2f pos = getPosition();

    if (!currentGame->checkWalls())
        setPosition((sf::Vector2f){pos.x + velocity->x * (time - deltaTime) / SPEED, pos.y});
    pos = getPosition();
    if (!currentGame->checkHeigth())
        setPosition((sf::Vector2f){pos.x, pos.y + velocity->y * (time - deltaTime) / SPEED});
    if (currentGame->isPlayerOnGround() && velocity->y > 0)
        velocity->y = 0;
    else
        velocity->y += currentGame->getCurrentRoom()->getGravity() * (time - deltaTime) / SPEED;
    if (velocity->y > MAX_FALL_SPEED)
        velocity->y = MAX_FALL_SPEED;
    pos = getPosition();
    getPlayerSprite()->setPosition(pos);
    currentGame->setViewCenter((sf::Vector2f){pos.x, pos.y - 125});
    setGround(currentGame->isPlayerOnGround());
    setDelta(time);
}
