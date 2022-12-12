#pragma once

#include "stdafx.h"
#include "mapObjects.h"
#include "creature.h"

class Map
{
protected:

	std::shared_ptr<Creature> m_playerPtr;

	std::shared_ptr<MapObj> m_UpObjPtr;
	std::shared_ptr<MapObj> m_DownObjPtr;
	std::shared_ptr<MapObj> m_LeftObjPtr;
	std::shared_ptr<MapObj> m_RightObjPtr;

	void upcastPtr(std::shared_ptr<MapObj> upcastingPtr);
private:
	int m_xSize;
	int m_ySize;
	int m_seed;

	std::array<std::array<std::shared_ptr<MapObj>, 25>, 25> m_mapVec;

	void getArea();
	
	void genObjects();
	template <class T>
	void fillWith();
	void setObjects();

	void swapPtrs(std::shared_ptr<MapObj> &first, std::shared_ptr<MapObj> &second);
	void move(char derection);

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Map(int xSize, int ySize);
	~Map();

	friend class Act;

	int getXSize() const;
	int getYSize() const;

	void controlPlayer();

	void generate();

	void refresh();

	void dbg();

	// std::vector<std::vector<std::unique_ptr<MapObj>>>& getMap();
};