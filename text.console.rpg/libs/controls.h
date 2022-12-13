#pragma once

#include "stdafx.h"
#include "map.h"

enum class Controls
{
	up		= VK_UP,
	down	= VK_DOWN,
	left	= VK_LEFT,
	right	= VK_RIGHT,
	exitU	= 'E' | 'e',
};

class ControlSystem
{
	friend class Map;
	friend class Map::Impl;
private:
	static void upcastPtr(std::shared_ptr<MapObj> upcastingPtr);
public:
	ControlSystem();
	~ControlSystem();

	static void takeControl();
	static void move(Controls button);

	class Impl;
	std::unique_ptr<Impl> d_;
};