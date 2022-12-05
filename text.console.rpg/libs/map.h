#pragma once

#include "stdafx.h"
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

	void move(char derection);

	class Impl;
	std::unique_ptr<Impl> d_;
protected:
	std::vector<std::vector<std::unique_ptr<MapObj>>> m_mapVec;

	auto* getPlayerPtr();
	auto* getUpObj();
	auto* getDownObj();
	auto* getLeftObj();
	auto* getRightObj();
public:
	Map(int xSize, int ySize);
	~Map();

	int getXSize() const;
	int getYSize() const;

	void controlPlayer();

	void generate();

	void refresh();

	void dbg();

	// std::vector<std::vector<std::unique_ptr<MapObj>>>& getMap();
};