#include "stdafx.h"
#include "player.h"

class Player::Impl { };

Player::Player() : d_(std::make_unique<Impl>()), 
	Creature(30, 5, 'P', 0, 0) { }
Player::Player(int health, int strength, char id, int posX, int posY) : d_(std::make_unique<Impl>()), 
	Creature(health, strength, id, posX, posY) { }
Player::Player(int posX, int posY) : d_(std::make_unique<Impl>()),
	Creature(30, 5, 'P', posX, posY) {}
Player::~Player() { }