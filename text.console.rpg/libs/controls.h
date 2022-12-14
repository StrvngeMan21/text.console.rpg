#pragma once

#include "stdafx.h"
#include "act.h"
#include "mapObjects.h"
#include "map.h"

enum class Controls
{
	up		= VK_UP,
	down	= VK_DOWN,
	left	= VK_LEFT,
	right	= VK_RIGHT,
	exitU	= 'E' | 'e',
};

class Map;
class Act;

class ControlSystem
{
	friend Map;
	friend Act;
private:
	static void upcastPtr(std::shared_ptr<MapObj> upcastingPtr);

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	ControlSystem();
	~ControlSystem();

	static void takeControl();
	static void move(Controls button);
};