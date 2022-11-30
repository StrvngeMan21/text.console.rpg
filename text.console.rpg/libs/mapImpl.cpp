#include "stdafx.h"
#include "map.h"

class Map::Impl { };

Map::Map(int xSize, int ySize) : d_(std::make_unique<Impl>()), m_xSize{ xSize }, m_ySize{ ySize } { }
Map::~Map() { };


void Map::mapGen() 
{
	
};