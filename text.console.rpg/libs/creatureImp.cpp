#include "stdafx.h"
#include "creature.h"

class Creature::Impl { };

Creature::Creature(int health, int strength, char id, int posX, int posY) : d_(std::make_unique<Impl>()), 
	MapObj(posX, posY, id),
	m_health{health}, m_str{strength} { }
Creature::Creature(int posX, int posY): d_(std::make_unique<Impl>()), 
	MapObj(posX, posY, m_id) { }
Creature::~Creature() { }
/*
void Creature::checkHealth() 
{ 
	if (m_health <= 0)
		//MapObj::~MapObj();
}
*/
int Creature::getHealth() const { return m_health; }
int Creature::getStrength() const { return m_str; }
char Creature::getId() const { return m_id; }

void Creature::setHealth(int health) { m_health = health; }
void Creature::setStrength(int strength) { m_str = strength; }
void Creature::setId(char id) { m_id = id; }
const char* Creature::getClass() const { return typeid(Creature).name(); }

void Creature::decHealthBy(int value) { m_health -= value; }
void Creature::getStatus(int& health, int& strength) { health = m_health; strength = m_str; }

void Creature::checkHealth()
{
	if (m_health <= 0)
		Creature::~Creature();
}

void Creature::printDbg() { std::cout << "Now I am here"; }