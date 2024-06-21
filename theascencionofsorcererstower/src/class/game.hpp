/*
** EPITECH PROJECT, 2024
** The ascencion of the sorcerer's tower
** File description:
** header
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <unordered_map>
#include "room.hpp"
#include "player.hpp"
#include "functional"

class Game {
public:
    Game();
    ~Game();

    bool isWindowOpen() const;
    void closeWindow();
    void clearWindow();
    void displayWindow();
    void switchFullscreen();
    void displayPlayer();
    bool isPlayerOnGround();
    bool isPlayerOnPlatform();
    sf::Color getPixelColor(sf::Vector2f pos);

    // Game loop

    void run();
    void draw();
    void event();
    void checkDoors();
    void playerEvent();

    bool checkWalls();
    bool checkLeft();
    bool checkRight();
    bool checkHeigth();
    bool checkFall();
    bool checkJump();

    //setter
    void setVideomode(sf::VideoMode videomode);
    void setTitle(sf::String title);
    void setWindow(sf::VideoMode mode, sf::String title, int style);
    void setView(sf::View view);
    void setViewCenter(sf::Vector2f pos);
    void setMusic(std::string path, std::string name);
    void setFullscreen(bool fullscreen);
    void setScene(scene_t scene);

    //getter
    sf::VideoMode getVideomode(void);
    sf::String getTitle(void);
    sf::RenderWindow &getWindow(void);
    sf::View getView(void);
    sf::Event getEvent(void);
    sf::Music *getMusic(std::string);
    bool getFullscreen(void);
    scene_t getScene(void);
    Player *getPlayer(void);
    Room *getRoom(scene_t name);
    Room *getCurrentRoom(void);

private:
    sf::VideoMode _videomode;
    sf::String _title;
    sf::RenderWindow _window;
    sf::View _view;
    sf::Event _event;
    std::unordered_map<std::string, sf::Music *> _music;
    bool _fullscreen;

    scene_t _scene;
    Player *_player;

    std::unordered_map<scene_t, Room *>_rooms = {
        {MENU, new Room(MENU)},
        {WALK, new Room(WALK)},
        {JUMP, new Room(JUMP)},
        {CROUCH, new Room(CROUCH)},
        {INTERACT, new Room(INTERACT)},
        {FIGHT, new Room(FIGHT)},
        {SHOP, new Room(SHOP),},
        {CHALLENGE, new Room(CHALLENGE)},
    };
};

extern Game *currentGame;
