#pragma once

#include "stdafx.h"

class MapObj
{
private:
	int m_xPos;
	int m_yPos;
	char m_id = 'O';

	class Impl;
	std::unique_ptr<Impl> d_;
protected:
public:
	MapObj();
	MapObj(int posX, int posY, char id);
	virtual ~MapObj();

	void getPos(int* posX, int* posY);
	virtual char getId() const;
	virtual const char* getClass() const;

	void setPos(int posX, int posY);
	virtual void setId(char id);

	friend std::ostream& operator<< (std::ostream& out, const MapObj& mapObj);
};