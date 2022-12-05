#pragma once

#include "stdafx.h"
//#include "mapChunk.h"
#include "mapObjects.h"
#include "creature.h"

class Map
{
private:
	int m_xSize = 25;
	int m_ySize = 25;
	int m_seed;

	template <class T>
	void fillWith();

	void setObjects();
	void genObjects();

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Map(int xSize, int ySize);
	~Map();

	int getXSize() const;
	int getYSize() const;

	std::vector<std::vector<std::unique_ptr<MapObj>>> m_mapVec;

	std::unique_ptr<Creature, std::default_delete<MapObj>> getPlayerPtr();
	std::unique_ptr<Creature, std::default_delete<MapObj>> getUpObj();
	std::unique_ptr<Creature, std::default_delete<MapObj>> getDownObj();
	std::unique_ptr<Creature, std::default_delete<MapObj>> getLeftObj();
	std::unique_ptr<Creature, std::default_delete<MapObj>> getRightObj();

	void generate();

	void refresh();

	void dbg();

	// std::vector<std::vector<std::unique_ptr<MapObj>>>& getMap();
};