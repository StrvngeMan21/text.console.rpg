#pragma once

#include "stdafx.h"
#include "mapObjects.h"
#include "creature.h"

class Map
{
protected:
	std::vector<std::vector<std::shared_ptr<MapObj>>> m_mapVec;

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

	void getArea();
	
	void genObjects();
	template <class T>
	void fillWith();
	void setObjects();

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