#include "stdafx.h"

#include "mapObjects.h"

class MapObj::Impl { };

MapObj::MapObj() : d_(std::make_unique<Impl>()),
	m_xPos{ 0 }, m_yPos{ 0 }, m_id{ 'O' } { }
MapObj::MapObj(int posX, int posY, char id) : d_(std::make_unique<Impl>()), 
	m_xPos{ posX }, m_yPos{ posY }, m_id{ id } { }
MapObj::~MapObj() { }

void MapObj::getPos(int* posX, int* posY) { *posX = m_xPos; *posY = m_yPos; }
char MapObj::getId() const { return m_id; }

void MapObj::setPos(int posX, int posY) { m_xPos = posX; m_yPos = posY; }
void MapObj::setId(char id) { m_id = id; }

const char* MapObj::getClass() const { return typeid(MapObj).name(); }

std::ostream& operator<< (std::ostream& out, const MapObj& mapObj)
{
	out << mapObj.getId();
	return out;
}