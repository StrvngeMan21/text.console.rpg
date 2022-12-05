#include "stdafx.h"
#include "enemy.h"

class Enemy::Impl { };

Enemy::Enemy(int health, int strength, char id, int posX, int posY) : d_(std::make_unique<Impl>()), 
	Creature(health, strength, id, posX, posY) { }
Enemy::Enemy(int posX, int posY) : d_(std::make_unique<Impl>()),
	Creature(15, 5, m_id, posX, posY) { }
Enemy::~Enemy() { }

char Enemy::getId() const { return m_id; }
const char* Enemy::getClass() const { return typeid(Enemy).name(); }

void Enemy::setId(char id) { m_id = id; }