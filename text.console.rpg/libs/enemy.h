#pragma once

#include "stdafx.h"
#include "creature.h"

class Enemy : public Creature
{
private:
	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Enemy();
	Enemy(int health, int strength, char id, int posX, int posY);
	Enemy(int posX, int posY);
	~Enemy();
};