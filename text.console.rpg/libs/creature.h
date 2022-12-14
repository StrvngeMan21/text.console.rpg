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
	virtual void checkHealth();

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Creature(int health, int strength, char id, int posX, int posY);
	Creature(int posX, int posY);
	virtual ~Creature();

	virtual int getHealth() const;
	virtual int getStrength() const;
	virtual char getId() const;
	virtual const char* getClass() const override;

	virtual void setHealth(int health);
	virtual void setStrength(int strength);
	virtual void setId(char id);

	virtual void decHealthBy(int value);
	virtual void getStatus(int& health, int& strength);

	void printDbg();
};