#include "stdafx.h"
#include "map.h"
#include "mapChunk.h"

class Map::Impl { };

Map::Map(int xSize, int ySize) : d_(std::make_unique<Impl>()), m_xSize{ xSize }, m_ySize{ ySize } { }
Map::~Map() 
{ 

};

int Map::getXSize() const { return m_xSize; };
int Map::getYSize() const { return m_ySize; };

void Map::mapGen() 
{

};