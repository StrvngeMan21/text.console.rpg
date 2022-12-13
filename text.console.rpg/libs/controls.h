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

class Map;

class ControlSystem
{
	friend Map;
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