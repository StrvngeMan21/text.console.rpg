#pragma once

#include "stdafx.h"
#include "creature.h"

class Player : public Creature
{
private:
	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Player();
	Player(int health, int strength, char id);
	~Player();
};