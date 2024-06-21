/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** room
*/

#include "room.hpp"

const std::string rooms_path[8] = {
    "menu_room(832x448).png",
    "walk_room(768x448).png",
    "jump_room(640x512).png",
    "crouch_room(640x512).png",
    "interact_room(832x416).png",
    "fight_room(960x384).png",
    "shop_room(1056x416).png",
    "epreuve_room(1056x832).png",
};

const sf::Vector2f rooms_origin[8] = {
    {96, 352},
    {96, 352},
    {96, 416},
    {96, 416},
    {96, 320},
    {96, 288},
    {96, 320},
    {96, 736},
};

const std::vector<std::pair<scene_t, std::vector<sf::Vector2f>>> rooms_door[8] = {
    {{MENU, {{80, 0}, {80, 0}}}, {WALK, {{320, 0}, {48, 0}}}, {CHALLENGE, {{560, 0}, {64, -512}}}},
    {{MENU, {{48, 0}, {320, 0}}}, {JUMP, {{528, 0}, {48, 0}}}},
    {{WALK, {{48, 0}, {528, 0}}}, {CROUCH, {{400, -224}, {48, -224}}}},
    {{JUMP, {{48, -224}, {400, -224}}}, {INTERACT, {{400, 0}, {48, 0}}}},
    {{CROUCH, {{48, 0}, {400, 0}}}, {FIGHT, {{592, 0}, {48, 0}}}},
    {{INTERACT, {{48, 0}, {592, 0}}}, {SHOP, {{712, 0}, {48, 0}}}},
    {{FIGHT, {{48, 0}, {712, 0}}}, {CHALLENGE, {{816, 0}, {48, 0}}}},
    {{SHOP, {{48, 0}, {816, 0}}}, {MENU, {{64, -512}, {560, 0}}}},
};

Room::Room(scene_t room)
{
    std::string file;
    std::vector<sf::Vector2f> test;

    file = rooms_path[room];
    _backtexture.loadFromFile("assets/background/" + file);
    _backsprite.setTexture(_backtexture);
    _backsprite.setOrigin(rooms_origin[room]);
    _foretexture.loadFromFile("assets/firstground/" + file);
    _foresprite.setTexture(_foretexture);
    _foresprite.setOrigin(rooms_origin[room]);
    _collisions.loadFromFile("assets/collision_sprite/" + file);
    _backsprite.setPosition((sf::Vector2f){0, 0});
    _foresprite.setPosition((sf::Vector2f){0, 0});
    for (int i = 0; i < (int)rooms_door[room].size(); i++) {
        this->addDoor(Door(rooms_door[room][i].first, rooms_door[room][i].second[0], rooms_door[room][i].second[1]), rooms_door[room][i].first);
    }
    _gravity = 0.01;
}

Room::~Room()
{
}

bool Room::isOnImage(sf::Vector2f pos)
{
    sf::Vector2u size = _collisions.getSize();

    if (pos.x < 0 || pos.x > size.x || pos.y < 0 || pos.y > size.y)
        return (false);
    return (true);
}

void Room::setBackSprite(sf::Sprite backsprite)
{
    _backsprite = backsprite;
}

void Room::setBackTexture(sf::Texture backtexture)
{
    _backtexture = backtexture;
}

void Room::setForeSprite(sf::Sprite foresprite)
{
    _foresprite = foresprite;
}

void Room::setForeTexture(sf::Texture foretexture)
{
    _foretexture = foretexture;
}

void Room::setCollisions(sf::Image collisions)
{
    _collisions = collisions;
}

void Room::addDoor(Door door, scene_t dest)
{
    _doors.insert(std::make_pair(dest, door));
}

sf::Sprite *Room::getBackSprite(void)
{
    return (&_backsprite);
}

sf::Texture *Room::getBackTexture(void)
{
    return (&_backtexture);
}

sf::Sprite *Room::getForeSprite(void)
{
    return (&_foresprite);
}

sf::Texture *Room::getForeTexture(void)
{
    return (&_foretexture);
}

sf::Image *Room::getCollisions(void)
{
    return (&_collisions);
}

std::unordered_map<scene_t, Door> Room::getDoors(void)
{
    return (_doors);
}

Door *Room::getDoorByDest(scene_t dest)
{
    return (&_doors[dest]);
}

float Room::getGravity(void)
{
    return (_gravity);
}

void Room::setGravity(float gravity)
{
    _gravity = gravity;
}
