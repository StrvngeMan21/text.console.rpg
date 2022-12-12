#include "stdafx.h"
#include "controls.h"
#include "mapObjects.h"
#include "map.h"
#include "heal.h"
#include "enemy.h"
#include "player.h"
#include "plain.h"
#include "act.h"

class ControlSystem::Impl { };


ControlSystem::ControlSystem() : d_(std::make_unique<Impl>())
{ }

void ControlSystem::upcastPtr(std::shared_ptr<MapObj> upcastingPtr)
{
	std::string origClass = upcastingPtr->getClass();
	try {
		if (origClass == typeid(Enemy).name() && typeid(upcastingPtr).name() != typeid(std::shared_ptr<Creature>()).name())
			upcastingPtr = std::dynamic_pointer_cast<Creature>(upcastingPtr);
		else if (origClass == typeid(HealEnt).name() && typeid(upcastingPtr).name() != typeid(std::shared_ptr<HealEnt>()).name())
			upcastingPtr = std::dynamic_pointer_cast<HealEnt>(upcastingPtr);
		throw - 1;
	}
	catch (int a)
	{
		std::cerr << "Something upcasted wierd";
	}
}


void ControlSystem::takeControl()
{
	int currentXPos, currentYPos;

	while (true)
	{
		Map::m_playerPtr->getPos(&currentXPos, &currentYPos);

		if (GetKeyState(VK_UP) & 0x8000 && currentYPos >= 1)
		{
			move(Controls::up);
			while (GetKeyState(VK_UP) & 0x8000) {}
		}

		if (GetKeyState(VK_DOWN) & 0x8000 && currentYPos <= Map::getYSize() - 2)
		{
			move(Controls::down);
			while (GetKeyState(VK_DOWN) & 0x8000) {}
		}

		if (GetKeyState(VK_LEFT) & 0x8000 && currentXPos >= 1)
		{
			move(Controls::left);
			while (GetKeyState(VK_LEFT) & 0x8000) {}
		}

		if (GetKeyState(VK_RIGHT) & 0x8000 && currentXPos <= Map::getXSize() - 2)
		{
			move(Controls::right);
			while (GetKeyState(VK_RIGHT) & 0x8000) {}
		}
	}
}

void ControlSystem::move(Controls button)
{
	Map::getArea();

	int pXPos, pYPos;
	int oXPos, oYPos;

	Map::m_playerPtr->getPos(&pXPos, &pYPos);

	switch (button)
	{
	case Controls::up:
		Map::m_UpObjPtr->getPos(&oXPos, &oYPos);
		if (Map::m_UpObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(Map::m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			Map::m_playerPtr->setPos(pXPos, pYPos - 1);
			Map::m_UpObjPtr->setPos(oXPos, oYPos + 1);

			Map::swapPtrs(Map::m_mapVec[pYPos][pXPos], Map::m_mapVec[oYPos][oXPos]);
		}
		break;
	case Controls::down:
		Map::m_DownObjPtr->getPos(&oXPos, &oYPos);
		if (Map::m_DownObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(Map::m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			Map::m_playerPtr->setPos(pXPos, pYPos + 1);
			Map::m_DownObjPtr->setPos(oXPos, oYPos - 1);

			Map::swapPtrs(Map::m_mapVec[pYPos][pXPos], Map::m_mapVec[oYPos][oXPos]);
		}
		break;
	case Controls::left:
		Map::m_LeftObjPtr->getPos(&oXPos, &oYPos);
		if (Map::m_LeftObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(Map::m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			Map::m_playerPtr->setPos(pXPos - 1, pYPos);
			Map::m_LeftObjPtr->setPos(oXPos + 1, oYPos);

			Map::swapPtrs(Map::m_mapVec[pYPos][pXPos], Map::m_mapVec[oYPos][oXPos]);
		}
		break;
	case Controls::right:
		Map::m_RightObjPtr->getPos(&oXPos, &oYPos);
		if (Map::m_RightObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(Map::m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			Map::m_playerPtr->setPos(pXPos + 1, pYPos);
			Map::m_RightObjPtr->setPos(oXPos - 1, oYPos);

			Map::swapPtrs(Map::m_mapVec[pYPos][pXPos], Map::m_mapVec[oYPos][oXPos]);
		}
	}
	Map::getArea();
	Map::refresh();
	Map::dbg();
}