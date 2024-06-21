/*
** EPITECH PROJECT, 2024
** TOAST
** File description:
** toast
*/

#pragma once

#include "door.hpp"
#include "object.hpp"
#include "room.hpp"
#include "player.hpp"
#include "game.hpp"

#define GRAVITY 0.01
#define MAX_FALL_SPEED 1
#define JUMP_HEIGHT 1.2

typedef void (*scene_tab_t)(Game *game);

void event_main_menu(Game *game, sf::Event event, scene_t room);
void anim_player(Game *game);
void move_player(Game *game, scene_t room);
void event_player(Game *game, scene_t room);

// scene
void scene_menu(Game *game);
void scene_walk(Game *game);
void scene_jump(Game *game);
void scene_crouch(Game *game);
void scene_interact(Game *game);
void scene_fight(Game *game);
void scene_shop(Game *game);
void scene_challenge(Game *game);
