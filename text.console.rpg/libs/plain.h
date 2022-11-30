#pragma once

#include "stdafx.h"

class Plain
{
private:
	int m_xPos;
	int m_yPos;

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	Plain();
	~Plain();
};