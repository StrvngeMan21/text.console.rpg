#pragma once

#include "stdafx.h"
#include "mapObjects.h"

class Plain: public MapObj
{
private:
	char m_id = '_';

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Plain(int posX, int posY);
	virtual ~Plain();

	virtual char getId() const;
	virtual const char* getClass() const override;

	virtual void setId(char id);
};