#include "stdafx.h"
#include "creature.h"

class Creature::Impl { };

Creature::Creature() : d_(std::make_unique<Impl>()) {}
Creature::Creature(int health, int strength, char id, int posX, int posY) : d_(std::make_unique<Impl>()), 
	m_health{health}, m_str{strength}, m_id{ id }, 
	m_xPos{ posX }, m_yPos{ posY } { }
Creature::Creature(int posX, int posY) : d_(std::make_unique<Impl>()), 
	m_xPos{ posX }, m_yPos{ posY } { }
Creature::~Creature() {}

int Creature::getHealth() const { return m_health; }
int Creature::getStrength() const { return m_str; }
char Creature::getId() const { return m_id; }
void Creature::getPos(int* posX, int* posY) { *posX = m_xPos; *posY = m_yPos; }

void Creature::setHealth(int health) { m_health = health; }
void Creature::setStrength(int strength) { m_str = strength; }
void Creature::setId(char id) { m_id = id; }
void Creature::setPos(int posX, int posY) { m_xPos = posX; m_yPos = posY; }

void Creature::printDbg() { std::cout << "Now I am here"; }