#include "stdafx.h"
#include "map.h"
#include "mapObjects.h"
#include "plain.h"
#include "player.h"
#include "enemy.h"
#include "heal.h"
#include "act.h"
#include "coldenstvo.h"

class Map::Impl { };

Map::Map(int xSize, int ySize) : d_(std::make_unique<Impl>()),
	m_xSize{ xSize }, m_ySize{ ySize }
{
	std::random_device rd;
	std::mt19937 seed(rd());
	m_seed = seed();
}

void Map::upcastPtr(std::shared_ptr<MapObj> upcastingPtr)
{
	std::string origClass = upcastingPtr->getClass();
	try {
		if (origClass == typeid(Enemy).name() && typeid(upcastingPtr).name() != typeid(std::shared_ptr<Creature>()).name())
			upcastingPtr = std::dynamic_pointer_cast<Creature>(upcastingPtr);
		else if (origClass == typeid(HealEnt).name() && typeid(upcastingPtr).name() != typeid(std::shared_ptr<HealEnt>()).name())
			upcastingPtr = std::dynamic_pointer_cast<HealEnt>(upcastingPtr);
		throw -1;
	} catch (int a)
	{
		std::cerr << "Something upcasted wierd";
	}
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

int Map::getXSize() const { return m_xSize; }
int Map::getYSize() const { return m_ySize; }

void Map::swapPtrs(std::shared_ptr<MapObj> &first, std::shared_ptr<MapObj> &second)
{
	std::shared_ptr<MapObj> temp;

	temp = std::move(second);
	second = std::move(first);
	first = std::move(temp);
}

void Map::move(char derection)
{
	getArea();

	int pXPos, pYPos;
	int oXPos, oYPos;

	m_playerPtr->getPos(&pXPos, &pYPos);

	switch (derection)
	{
	case 'u':
		m_UpObjPtr->getPos(&oXPos, &oYPos);
		if (m_UpObjPtr->getClass() == typeid(Player).name())
		{
			m_playerPtr->setPos(pXPos, pYPos - 2);
			m_UpObjPtr->setPos(oXPos, oYPos + 2);
		}
		else if (m_UpObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			m_playerPtr->setPos(pXPos, pYPos - 1);
			m_UpObjPtr->setPos(oXPos, oYPos + 1);

			swapPtrs(m_mapVec[pYPos][pXPos], m_mapVec[oYPos][oXPos]);
		}
		break;
	case 'd':
		m_DownObjPtr->getPos(&oXPos, &oYPos);
		if (m_DownObjPtr->getClass() == typeid(Player).name())
		{
			m_playerPtr->setPos(pXPos, pYPos + 2);
			m_DownObjPtr->setPos(oXPos, oYPos - 2);
		}
		else if (m_DownObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			m_playerPtr->setPos(pXPos, pYPos + 1);
			m_DownObjPtr->setPos(oXPos, oYPos - 1);

			swapPtrs(m_mapVec[pYPos][pXPos], m_mapVec[oYPos][oXPos]);
		}
		break;
	case 'l':
		m_LeftObjPtr->getPos(&oXPos, &oYPos);
		if (m_LeftObjPtr->getClass() == typeid(Player).name())
		{
			m_playerPtr->setPos(pXPos - 2, pYPos);
			m_LeftObjPtr->setPos(oXPos + 2, oYPos);
		}
		else if (m_LeftObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
			m_playerPtr->setPos(pXPos - 1, pYPos);
			m_LeftObjPtr->setPos(oXPos + 1, oYPos);

			swapPtrs(m_mapVec[pYPos][pXPos], m_mapVec[oYPos][oXPos]);
		}
		break;
	case 'r':
		m_RightObjPtr->getPos(&oXPos, &oYPos);
		if (m_RightObjPtr->getClass() == typeid(Player).name())
		{
			m_playerPtr->setPos(pXPos + 2, pYPos);
			m_RightObjPtr->setPos(oXPos - 2, oYPos);
		}
		else if (m_RightObjPtr->getClass() != typeid(Plain).name())
		{
			upcastPtr(m_UpObjPtr);
			//Act::act(m_playerPtr, m_UpObjPtr);
		}
		else
		{
 			m_playerPtr->setPos(pXPos + 1, pYPos);
			m_RightObjPtr->setPos(oXPos - 1, oYPos);

			swapPtrs(m_mapVec[pYPos][pXPos], m_mapVec[oYPos][oXPos]);
		}
	}
	getArea();
	refresh();
	dbg();
}

void Map::controlPlayer()
{
	int currentXPos, currentYPos;

	while (true)
	{
		m_playerPtr->getPos(&currentXPos, &currentYPos);

		if (GetKeyState(VK_UP) & 0x8000 && currentYPos >= 1)
		{
			move('u');
			while (GetKeyState(VK_UP) & 0x8000) {}
		}

		if (GetKeyState(VK_DOWN) & 0x8000 && currentYPos <= m_ySize - 2)
		{
			move('d');
			while (GetKeyState(VK_DOWN) & 0x8000) {}
		}

		if (GetKeyState(VK_LEFT) & 0x8000 && currentXPos >= 1)
		{
			move('l');
			while (GetKeyState(VK_LEFT) & 0x8000) {}
		}

		if (GetKeyState(VK_RIGHT) & 0x8000 && currentXPos <= m_ySize - 2)
		{
			move('r');
			while (GetKeyState(VK_RIGHT) & 0x8000) {}
		}
	}
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

	char renderMap[25][25];

	for (int y = 0; y < m_mapVec.size(); y++)
	{
		for (int x = 0; x < m_mapVec[y].size(); x++)
		{
			int objPosX, objPosY;
			m_mapVec[y][x]->getPos(&objPosX, &objPosY);
			/*
			m_mapVec[y][x]->getPos(&objPosX, &objPosY);
			renderMap[objPosY][objPosX] = m_mapVec[y][x]->getId();*/
			std::cout << m_mapVec.at(objPosY).at(objPosX)->getId();
		}
		std::cout << std::endl;
	}
	/*for (int y = 0; y < m_mapVec.size(); y++)
	{
		for (int x = 0; x < m_mapVec[y].size(); x++)
		{
			std::cout << renderMap[y][x];
		}
		std::cout << std::endl;
	}*/
}

void Map::dbg()
{
	/*m_playerPtr->printDbg();
	std::cout << typeid(m_playerPtr).name();

	m_playerPtr = std::make_shared<Enemy>(2, 2);
	std::cout << typeid(m_playerPtr).name() << " " << m_playerPtr->getId();
	*/
	std::cout << m_UpObjPtr->getId() << " " << m_DownObjPtr->getId() << " " << m_LeftObjPtr->getId() << " " << m_RightObjPtr->getId() << std::endl;
}