#pragma once

#include "stdafx.h"

class Act
{
private:
	friend class Map;

	template <class T1, class T2>
	static void fight(const T1& player, const T2& obj);

	template <class T1, class T2>
	static void take(const T1& player, const T2& obj);

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	template <class T1, class T2>
	static void act(const T1& player, const T2& obj);
	
	static void dbg();
};