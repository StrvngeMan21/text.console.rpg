#include "stdafx.h"
#include "mapObjects.h"
#include "controls.h"
#include "act.h"
#include "plain.h"

class ControlSystem::Impl { };


/*
ControlSystem::ControlSystem(const Map& map) : d_(std::make_unique<Impl>()),
	m_map{ map } { }

void ControlSystem::Move()
{
	auto playerPtr = m_map->;
	int currentPlayerPosX, currentPlayerPosY;
	m_map->getPos(&currentPlayerPosX, &currentPlayerPosY);

	std::unique_ptr<Creature, std::default_delete<MapObj>> up		= map.getUpObj();
	std::unique_ptr<Creature, std::default_delete<MapObj>> down		= map.getDownObj();
	std::unique_ptr<Creature, std::default_delete<MapObj>> left		= map.getLeftObj();
	std::unique_ptr<Creature, std::default_delete<MapObj>> right	= map.getRightObj();

	std::cout << up->getId();

	if (GetAsyncKeyState(VK_UP))
	{
		if (map.m_mapVec[currentPlayerPosY - 1][currentPlayerPosX]->getClass() != typeid(Plain).name())
			Act::act(playerPtr,up);
	}
}
*/