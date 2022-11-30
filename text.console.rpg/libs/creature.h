#pragma once

#include "stdafx.h"

class Creature
{
private:
	int m_xPos;
	int m_yPos;

	int m_health = 15;
	int m_str = 5;
	char m_id = 'C';

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Creature();
	Creature(int health, int strength, char id);
	~Creature();

	int getHealth() const;
	int getStrength() const;
	char getId() const;

	void setHealth(int health);
	void setStrength(int strength);
	void setId(char id);

	void printDbg();
};