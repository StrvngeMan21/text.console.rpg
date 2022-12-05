#pragma once

#include "stdafx.h"
#include "map.h"

enum class Controls
{
	up		= VK_UP,
	down	= VK_DOWN,
	left	= VK_LEFT,
	right	= VK_RIGHT,
	saveU	= 'S',
	saveD	= 's',
	exitU	= 'E',
	ecitD	= 'e'
};

class ControlSystem
{
private:
	Controls m_ctrl;
	Map& m_map;

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	ControlSystem(const Map& map);
	~ControlSystem();
	static void Move();
};