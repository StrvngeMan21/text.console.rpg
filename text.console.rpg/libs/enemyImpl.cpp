#include "stdafx.h"
#include "enemy.h"

class Enemy::Impl { };

Enemy::Enemy() : d_(std::make_unique<Impl>()), 
	Creature(15, 5, 'E', 0, 0) { }
Enemy::Enemy(int health, int strength, char id, int posX, int posY) : d_(std::make_unique<Impl>()), 
	Creature(health, strength, id, posX, posY) { }
Enemy::Enemy(int posX, int posY) : d_(std::make_unique<Impl>()),
	Creature(15, 5, 'E', posX, posY) { }
Enemy::~Enemy() { }