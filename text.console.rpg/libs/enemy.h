#pragma once

#include "stdafx.h"
#include "creature.h"

class Enemy : public Creature
{
private:
	char m_id = 'E';

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Enemy(int health, int strength, char id, int posX, int posY);
	Enemy(int posX, int posY);
	virtual ~Enemy();

	virtual char getId() const;
	virtual const char* getClass() const override;

	virtual void setId(char id);
};