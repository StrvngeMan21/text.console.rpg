#pragma once

#include "stdafx.h"

class StatusBar
{
private:
	class Impl;
	std::unique_ptr<Impl> d_;
public:
	static void refreshStatus();
};