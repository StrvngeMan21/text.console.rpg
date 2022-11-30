#pragma once

#include "stdafx.h"
#include "mapChunk.h"

class Map
{
private:
	int m_xSize = 25;
	int m_ySize = 25;

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Map(int xSize, int ySize);
	~Map();

	int getXSize() const;
	int getYSize() const;

	void mapGen();
};