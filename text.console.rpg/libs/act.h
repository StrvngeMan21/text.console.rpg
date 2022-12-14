#pragma once

#include "stdafx.h"
#include "map.h"
#include "controls.h"
#include "mapObjects.h"
#include "creature.h"
#include "player.h"
#include "enemy.h"
#include "heal.h"
#include "plain.h"

class Map;
class ControlSystem;

class Act
{
	friend Map;
	friend ControlSystem;
private:
	template <class T1, class T2>
	static void fight(const T1 player, const T2 obj);

	template <class T1, class T2>
	static void take(T1 player, T2 obj);

	class Impl;
	std::unique_ptr<Impl> d_;
public:
	template <class T1, class T2>
	static void act(const T1 player, const T2 obj);
	
	static void dbg();
};

template <class T1, class T2>
void Act::act(T1 player, T2 obj)
{
	if (typeid(T2).name() == typeid(Enemy).name())
	{
		dynamic_cast<Player>(T1).decHealthBy(T2.getStrength());
		dynamic_cast<Enemy>(T2).decHealthBy(T1.getStrength());
	}
	if (typeid(T2).name() == typeid(HealEnt).name())
	{

	}
}

template <class T1, class T2>
void Act::fight(T1 player, T2 obj)
{
	dynamic_cast<Player>(T1).decHealthBy(T2.getStrength());
	dynamic_cast<Enemy>(T2).decHealthBy(T1.getStrength());
}