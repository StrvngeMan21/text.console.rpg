#pragma once

#include "stdafx.h"
#include "mapObjects.h"
#include "creature.h"
#include "controls.h"

class Map
{
	friend class ControlSystem;
protected:
	static int m_xSize;
	static int m_ySize;

	static std::array<std::array<std::shared_ptr<MapObj>, 25>, 25> m_mapVec;

	static std::shared_ptr<Creature> m_playerPtr;

	static std::shared_ptr<MapObj> m_UpObjPtr;
	static std::shared_ptr<MapObj> m_DownObjPtr;
	static std::shared_ptr<MapObj> m_LeftObjPtr;
	static std::shared_ptr<MapObj> m_RightObjPtr;

	static void getArea();
private:
	int m_seed;

	void genObjects();
	template <class T>
	void fillWith();
	void setObjects();

	static void swapPtrs(std::shared_ptr<MapObj> &first, std::shared_ptr<MapObj> &second);

public:
	Map();
	~Map();

	static int getXSize();
	static int getYSize();

	void generate();

	static void refresh();

	static void dbg();

	class Impl;
	std::unique_ptr<Impl> d_;
};