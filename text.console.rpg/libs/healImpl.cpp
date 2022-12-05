#include "stdafx.h"
#include "heal.h"

class HealEnt::Impl { };

HealEnt::HealEnt(int posX, int posY) : d_(std::make_unique<Impl>()), 
	MapObj(posX, posY, m_id) { }
HealEnt::~HealEnt() { }

char HealEnt::getId() const { return m_id; }
const char* HealEnt::getClass() const { return typeid(HealEnt).name(); }

void HealEnt::setId(char id) { m_id = id; }