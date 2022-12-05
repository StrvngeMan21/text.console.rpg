#include "stdafx.h"
#include "player.h"

class Player::Impl { };

Player::Player(int health, int strength, char id, int posX, int posY) : d_(std::make_unique<Impl>()), 
	Creature(health, strength, id, posX, posY) { }
Player::Player(int posX, int posY) : d_(std::make_unique<Impl>()),
	Creature(30, 5, m_id, posX, posY) {}
Player::~Player() { }

void Player::addSteps() { m_stepCount += 1; }

int Player::getSteps() const { return m_stepCount; }
char Player::getId() const { return m_id; }
const char* Player::getClass() const { return typeid(Player).name(); }

void Player::setSteps(int value) { m_stepCount = value; }
void Player::setId(char id) { m_id = id; }