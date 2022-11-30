#include "stdafx.h"
#include "player.h"

class Player::Impl { };

Player::Player() : d_(std::make_unique<Impl>()), Creature(30, 5, 'P') { }
Player::Player(int health, int strength, char id) : d_(std::make_unique<Impl>()), Creature(health, strength, id) { }
Player::~Player() { }