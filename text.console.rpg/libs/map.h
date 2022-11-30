#pragma once

#include "stdafx.h"
#include "enemy.h"
#include "player.h"

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

	void getXSize() const;
	void getYSize() const;

	void mapGen();
};