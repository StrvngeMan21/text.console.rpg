#pragma once

#include "stdafx.h"
#include "mapObjects.h"

class Creature : public MapObj
{
protected:
	int m_health = 15;
	int m_str = 5;
	char m_id = 'C';
private:
	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Creature(int health, int strength, char id, int posX, int posY);
	Creature(int posX, int posY);
	virtual ~Creature();

	int getHealth() const;
	int getStrength() const;
	virtual char getId() const;
	virtual const char* getClass() const override;

	void setHealth(int health);
	void setStrength(int strength);
	virtual void setId(char id);

	void decHealthBy(int value);
	void getStatus(int& health, int& strength);

	virtual void checkHealth();

	void printDbg();
};