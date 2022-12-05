#include "stdafx.h"
#include "map.h"
#include "mapObjects.h"
#include "plain.h"
#include "player.h"
#include "enemy.h"
#include "heal.h"
#include "coldenstvo.h"

class Map::Impl { };

Map::Map(int xSize, int ySize) : d_(std::make_unique<Impl>()),
	m_xSize{ xSize }, m_ySize{ ySize }
{
	std::random_device rd;
	std::mt19937 seed(rd());
	m_seed = seed();
}

Map::~Map() { }

int Map::getXSize() const { return m_xSize; }
int Map::getYSize() const { return m_ySize; }

template <class T>
void Map::fillWith()
{
	std::random_device rd;
	std::mt19937 rnd(rd());

	std::uniform_int_distribution<int> randX(0, m_xSize - 1);
	std::uniform_int_distribution<int> randY(0, m_ySize - 1);

	for (int iii = 0; iii < 5; iii++)
	{
		int x = randX(rnd);
		int y = randY(rnd);

		if (m_mapVec[y][x]->getClass() == typeid(Plain).name())
			m_mapVec[y][x] = std::make_unique<T>(x, y);
		else
		{
			while (m_mapVec[y][x]->getClass() == typeid(Plain).name())
			{
				x = randX(rnd);
				y = randY(rnd);
			}
			m_mapVec[y][x] = std::make_unique<T>(x, y);
		}
	}
}

void Map::genObjects() 
{
	int playerPosX = m_xSize / 2;
	int playerPosY = m_ySize / 2;

	m_mapVec[playerPosY][playerPosX] = std::make_unique<Player>(playerPosX, playerPosY);

	fillWith<Enemy>();
	fillWith<HealEnt>();

	setObjects();
}

void Map::setObjects()
{
	for (int y = 0; y < m_mapVec.size(); y++)
	{
		for (int x = 0; x < m_mapVec[y].size(); x++)
		{
			int objPosX, objPosY;
			m_mapVec[y][x]->getPos(&objPosX, &objPosY);
			m_mapVec[y][x]->setPos(objPosX, objPosY);
		}
	}
}

std::unique_ptr<Creature, std::default_delete<MapObj>> Map::getPlayerPtr()
{
	auto ass = static_unique_ptr_cast<Creature, MapObj, std::default_delete<MapObj>>(m_mapVec[m_ySize / 2][m_xSize / 2]);
	return ass;
}
std::unique_ptr<Creature, std::default_delete<MapObj>> Map::getUpObj()
{
	int xCurrentPos, yCurrentPos;

	auto player = getPlayerPtr();
	player->getPos(&xCurrentPos, &yCurrentPos);

	return static_unique_ptr_cast<Creature, MapObj, std::default_delete<MapObj>>(m_mapVec[yCurrentPos-1][xCurrentPos]);
}
std::unique_ptr<Creature, std::default_delete<MapObj>> Map::getDownObj()
{
	int xCurrentPos, yCurrentPos;

	auto player = getPlayerPtr();
	player->getPos(&xCurrentPos, &yCurrentPos);

	return static_unique_ptr_cast<Creature, MapObj, std::default_delete<MapObj>>(m_mapVec[yCurrentPos - 1][xCurrentPos]);
}
std::unique_ptr<Creature, std::default_delete<MapObj>> Map::getLeftObj()
{
	int xCurrentPos, yCurrentPos;

	auto player = getPlayerPtr();
	player->getPos(&xCurrentPos, &yCurrentPos);

	return static_unique_ptr_cast<Creature, MapObj, std::default_delete<MapObj>>(m_mapVec[yCurrentPos - 1][xCurrentPos]);
}
std::unique_ptr<Creature, std::default_delete<MapObj>> Map::getRightObj()
{
	int xCurrentPos, yCurrentPos;

	auto player = getPlayerPtr();
	player->getPos(&xCurrentPos, &yCurrentPos);

	return static_unique_ptr_cast<Creature, MapObj, std::default_delete<MapObj>>(m_mapVec[yCurrentPos - 1][xCurrentPos]);
}


void Map::generate() 
{
	for (int y = 0; y < m_ySize; y++)
	{
		std::vector<std::unique_ptr<MapObj>> tempVec;

		for (int x = 0; x < m_ySize; x++)
		{
			tempVec.push_back(std::make_unique<Plain>(x, y));
		}
		m_mapVec.push_back(std::move(tempVec));
	}
	genObjects();
}

void Map::refresh()
{
	for (int y = 0; y < m_mapVec.size(); y++)
	{
		for (int x = 0; x < m_mapVec[y].size(); x++)
		{
			int objPosX, objPosY;
			m_mapVec[y][x]->getPos(&objPosX, &objPosY);

			std::cout << m_mapVec[objPosY][objPosX]->getId();
		}
		std::cout << std::endl;
	}
}

void Map::dbg()
{
	std::cout << m_seed << std::endl;

	refresh();

	std::cout << static_cast<Creature*>(m_mapVec[12][12].get())->getHealth();
}