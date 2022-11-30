#include "stdafx.h"
#include "enemy.h"

class Enemy::Impl { };

Enemy::Enemy() : d_(std::make_unique<Impl>()), Creature(15, 5, 'E') { }
Enemy::Enemy(int health, int strength, char id) : d_(std::make_unique<Impl>()), Creature(health, strength, id) { }
Enemy::~Enemy() { }