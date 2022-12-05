#pragma once

#include "stdafx.h"
#include "mapObjects.h"

class HealEnt : public MapObj
{
private:
	char m_id = 'H';

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	HealEnt(int posX, int posY);
	virtual ~HealEnt();

	virtual char getId() const;
	virtual const char* getClass() const override;

	virtual void setId(char id);
};