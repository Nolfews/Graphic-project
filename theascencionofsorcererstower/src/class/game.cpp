/*
** EPITECH PROJECT, 2024
** The ascencion of the sorcerer's tower
** File description:
** game
*/

#include "game.hpp"

#define JUMP_HEIGHT 1.2

Game::Game()
{
    _title = "The ascencion of the sorcerer's tower";
    _view.setSize((sf::Vector2f){568, 320});
    _view.setCenter((sf::Vector2f){832 / 2, 0});
    _videomode = (sf::VideoMode){1920, 1080, 32};
    setWindow(_videomode, _title, sf::Style::Close | sf::Style::Resize);
    _window.setView(_view);
    _fullscreen = false;
    _scene = MENU;
    _player = new Player();
    _window.setFramerateLimit(300);
}

Game::~Game()
{
    _window.close();
}

bool Game::isWindowOpen() const
{
    return _window.isOpen();
}

void Game::closeWindow()
{
    _window.close();
}

void Game::clearWindow()
{
    _window.clear(sf::Color::Black);
}

void Game::displayWindow()
{
    _window.display();
}

void Game::switchFullscreen()
{
    if (_fullscreen) {
        _window.create(_videomode, _title, 6);
        Game::setFullscreen(false);
    } else {
        _window.create(_videomode, _title, 14);
        Game::setFullscreen(true);
    }
}

void Game::setMusic(std::string path, std::string name)
{
    for (auto &elem : _music) {
        if (elem.first == name)
            return;
    }
    sf::Music *music = NULL;
    music->openFromFile(path);
    _music[name] = music;
}

sf::Music *Game::getMusic(std::string name)
{
    for (auto &elem : _music) {
        if (elem.first == name)
            return (elem.second);
    }
    return (NULL);
}

void Game::displayPlayer(void)
{
    getWindow().draw(*getPlayer()->getPlayerSprite());
}

void Game::setViewCenter(sf::Vector2f pos)
{
    _view.setCenter((sf::Vector2f){pos.x, pos.y});
    _window.setView(_view);
}

void Game::setVideomode(sf::VideoMode videomode)
{
    _videomode = videomode;
}

void Game::setTitle(sf::String title)
{
    _title = title;
}

void Game::setWindow(sf::VideoMode mode, sf::String title, int style)
{
    _window.create(mode, title, style);
}

void Game::setView(sf::View view)
{
    _view = view;
}

void Game::setFullscreen(bool fullscreen)
{
    _fullscreen = fullscreen;
}

void Game::setScene(scene_t scene)
{
    _scene = scene;
}

sf::VideoMode Game::getVideomode(void)
{
    return _videomode;
}

sf::String Game::getTitle(void)
{
    return _title;
}

sf::RenderWindow &Game::getWindow(void)
{
    return _window;
}

sf::View Game::getView(void)
{
    return _view;
}

sf::Event Game::getEvent(void)
{
    return _event;
}

bool Game::getFullscreen(void)
{
    return _fullscreen;
}

scene_t Game::getScene(void)
{
    return _scene;
}

Player *Game::getPlayer(void)
{
    return _player;
}

Room *Game::getRoom(scene_t scene)
{
    return _rooms[scene];
}

bool Game::isPlayerOnPlatform()
{
    sf::Vector2f bottom = getPlayer()->getPosition();

    for (float i = -10.5; i <= 10.5; i += 10.5) {
        if (getPixelColor((sf::Vector2f){bottom.x + i, bottom.y + 1}).b == 255)
            return (true);
    }
    return (false);
}

sf::Color Game::getPixelColor(sf::Vector2f pos)
{
    sf::Vector2f off = getCurrentRoom()->getBackSprite()->getOrigin();
    sf::Image col = *getCurrentRoom()->getCollisions();
    sf::Vector2u size = col.getSize();

    if (pos.x + off.x < 0 || pos.x + off.x >= size.x || pos.y + off.y < 0 || pos.y + off.y >= size.y)
        return (sf::Color::Red);
    return (col.getPixel((int)(pos.x + off.x), (int)(pos.y + off.y)));
}

bool Game::isPlayerOnGround()
{
    sf::Vector2f bottom = getPlayer()->getPosition();

    for (float i = -10.5; i <= 10.5; i += 10.5) {
        if (getPixelColor((sf::Vector2f){bottom.x + i, bottom.y + 1}).r == 255 ||
            getPixelColor((sf::Vector2f){bottom.x + i, bottom.y + 1}).b == 255)
            return (true);
    }
    return (false);
}
void Game::draw()
{
    Room *room = getRoom(getScene());

    clearWindow();
    getWindow().draw(*room->getBackSprite());
    for (auto &door : room->getDoors()) {
        sf::Texture texture = *door.second.getTexture();
        sf::Sprite sprite = sf::Sprite(texture);

        sprite.setOrigin(door.second.getSprite()->getOrigin());
        sprite.setTextureRect(door.second.getSprite()->getTextureRect());
        sprite.setPosition(door.second.getSprite()->getPosition());
        getWindow().draw(sprite);
    }
    getWindow().draw(*getPlayer()->getPlayerSprite());
    getWindow().draw(*room->getForeSprite());
    displayWindow();
}

void Game::run()
{
    while (isWindowOpen()) {
        event();
        getPlayer()->update();
        draw();
    }
}

void Game::checkDoors()
{
    for (auto &door : getCurrentRoom()->getDoors()) {
        if (door.second.isOnDoor(getPlayer()->getPosition(), isPlayerOnGround())) {
            setScene(door.second.getDest());
            getPlayer()->setPosition(door.second.getDestPos() + sf::Vector2f{0, -1});
            break;
        }
    }
}

void Game::event()
{
    sf::Event event;

    playerEvent();
    while (getWindow().pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            closeWindow();
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F)
            checkDoors();
    }
}

void Game::playerEvent()
{
    getPlayer()->getVelocity()->x = 0;
    getPlayer()->setCrouching(false);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        getPlayer()->getVelocity()->x += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        getPlayer()->setPosition((sf::Vector2f){20, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        getPlayer()->getVelocity()->x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isPlayerOnGround())
        getPlayer()->getVelocity()->y = -JUMP_HEIGHT;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isPlayerOnPlatform())
        getPlayer()->setCrouching(true);
}

bool Game::checkRight()
{
    sf::Vector2f pos = getPlayer()->getPosition();
    sf::Vector2f velocity = *getPlayer()->getVelocity();
    float time = getPlayer()->getMovementClock()->getElapsedTime().asMilliseconds();
    float deltaTime = getPlayer()->getDelta();

    pos.x = pos.x + (float)10.5;
    for (float y = 0; y <= 28; y += 14) {
        if (getPixelColor((sf::Vector2f){pos.x + velocity.x * (time - deltaTime) / SPEED, pos.y - y}).r == 255)
            return (true);
        if (velocity.y > 0 &&
            getPixelColor((sf::Vector2f){pos.x + velocity.x * (time - deltaTime) / SPEED, pos.y - y}).b == 255)
            return (true);
    }
    return (false);
}

bool Game::checkLeft()
{
    sf::Vector2f pos = getPlayer()->getPosition();
    sf::Vector2f velocity = *getPlayer()->getVelocity();
    float time = getPlayer()->getMovementClock()->getElapsedTime().asMilliseconds();
    float deltaTime = getPlayer()->getDelta();

    pos.x = pos.x - (float)10.5;
    for (float y = 0; y <= 28; y += 14) {
        if (getPixelColor((sf::Vector2f){pos.x + velocity.x * (time - deltaTime) / SPEED, pos.y - y}).r == 255)
            return (true);
        if (velocity.y > 0 &&
            getPixelColor((sf::Vector2f){pos.x + velocity.x * (time - deltaTime) / SPEED, pos.y - y}).b == 255)
            return (true);
    }
    return (false);
}

bool Game::checkWalls()
{
    sf::Vector2f velocity = *getPlayer()->getVelocity();

    if (velocity.x > 0)
        return (checkRight());
    if (velocity.x < 0)
        return (checkLeft());
    return (false);
}

bool Game::checkFall()
{
    sf::Vector2f pos = getPlayer()->getPosition();
    sf::Vector2f velocity = *getPlayer()->getVelocity();
    float time = getPlayer()->getMovementClock()->getElapsedTime().asMilliseconds();
    float deltaTime = getPlayer()->getDelta();

    for (float i = -10.5; i <= 10.5; i += 10.5) {
        if (getPixelColor((sf::Vector2f){pos.x + i, pos.y + velocity.y * (time - deltaTime) / SPEED}).r == 255)
            return (true);
        if (getPixelColor((sf::Vector2f){pos.x + i, pos.y + velocity.y * (time - deltaTime) / SPEED}).b == 255)
            return (true);
    }
    return (false);
}

bool Game::checkJump()
{
    sf::Vector2f pos = getPlayer()->getPosition();
    sf::Vector2f velocity = *getPlayer()->getVelocity();
    float time = getPlayer()->getMovementClock()->getElapsedTime().asMilliseconds();
    float deltaTime = getPlayer()->getDelta();

    pos.y = pos.y - (float)28;
    for (float i = -10.5; i <= 10.5; i += 10.5) {
        if (getPixelColor((sf::Vector2f){pos.x + i, pos.y + velocity.y * (time - deltaTime) / SPEED}).r == 255)
            return (true);
    }
    return (false);
}

bool Game::checkHeigth()
{
    sf::Vector2f *velocity = getPlayer()->getVelocity();

    if (velocity->y > 0)
        return (checkFall());
    if (velocity->y < 0)
        return (checkJump());
    if (isPlayerOnPlatform() && getPlayer()->getCrouching())
        velocity->y = 2;
    return (false);
}

Room *Game::getCurrentRoom(void)
{
    return _rooms[_scene];
}
