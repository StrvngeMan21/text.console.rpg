#pragma once

#include "stdafx.h"
#include "creature.h"

class Player : public Creature
{
private:
	char m_id = 'P';
	int m_stepCount = 0;

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Player(int health, int strength, char id, int posX, int posY);
	Player(int posX, int posY);
	virtual ~Player();

	void addSteps();

	int getSteps() const;
	virtual char getId() const;
	virtual const char* getClass() const override;

	void setSteps(int value);
	virtual void setId(char id);
};