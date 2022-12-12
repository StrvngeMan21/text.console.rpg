#include "stdafx.h"
#include "map.h"
#include "mapObjects.h"
#include "plain.h"
#include "player.h"
#include "enemy.h"
#include "heal.h"
#include "act.h"

class Map::Impl { };

Map::Map() : d_(std::make_unique<Impl>())
{
	std::random_device rd;
	std::mt19937 seed(rd());
	m_seed = seed();
	m_ySize = 25;
	m_xSize = 25;
}

void Map::getArea()
{
	int xCurrentPos, yCurrentPos;
	m_playerPtr->getPos(&xCurrentPos, &yCurrentPos);

	if (yCurrentPos != 0)
		m_UpObjPtr		= m_mapVec[yCurrentPos - 1][xCurrentPos];
	if (yCurrentPos != 24)
		m_DownObjPtr	= m_mapVec[yCurrentPos + 1][xCurrentPos];
	if (xCurrentPos != 0)
		m_LeftObjPtr	= m_mapVec[yCurrentPos][xCurrentPos - 1];
	if (xCurrentPos != 24)
		m_RightObjPtr	= m_mapVec[yCurrentPos][xCurrentPos + 1];
}

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
			m_mapVec[y][x] = std::move(std::make_shared<T>(x, y));
		else
		{
			while (m_mapVec[y][x]->getClass() != typeid(Plain).name())
			{
				x = randX(rnd);
				y = randY(rnd);
			}
			m_mapVec[y][x] = std::move(std::make_shared<T>(x, y));
		}
	}
}
void Map::genObjects() 
{
	int playerPosX = m_xSize / 2;
	int playerPosY = m_ySize / 2;

	m_mapVec[playerPosY][playerPosX] = std::move(std::make_shared<Player>(playerPosX, playerPosY));
	m_playerPtr = std::dynamic_pointer_cast<Creature>(m_mapVec[playerPosY][playerPosX]);

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

Map::~Map() { }

int Map::getXSize() { return m_xSize; }
int Map::getYSize() { return m_ySize; }

void Map::swapPtrs(std::shared_ptr<MapObj> &first, std::shared_ptr<MapObj> &second)
{
	std::shared_ptr<MapObj> temp;

	temp = std::move(second);
	second = std::move(first);
	first = std::move(temp);
}

void Map::generate() 
{
	for (int y = 0; y < m_ySize; y++)
	{
		for (int x = 0; x < m_ySize; x++)
		{
			m_mapVec[y][x] = std::move(std::make_shared<Plain>(x, y));
		}
	}
	genObjects();
}

void Map::refresh()
{
	system("cls");

	for (int y = 0; y < m_mapVec.size(); y++)
	{
		for (int x = 0; x < m_mapVec[y].size(); x++)
		{
			std::cout << m_mapVec.at(y).at(x)->getId();
		}
		std::cout << std::endl;
	}

}

void Map::dbg()
{
	/*m_playerPtr->printDbg();
	std::cout << typeid(m_playerPtr).name();

	m_playerPtr = std::make_shared<Enemy>(2, 2);
	std::cout << typeid(m_playerPtr).name() << " " << m_playerPtr->getId();
	*/
	std::cout << m_UpObjPtr->getId() << " " << m_DownObjPtr->getId() << " " << m_LeftObjPtr->getId() << " " << m_RightObjPtr->getId() << " " << m_playerPtr->getHealth() << std::endl;
}