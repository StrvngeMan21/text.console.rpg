#include "stdafx.h"
#include "act.h"
#include "player.h"
#include "plain.h"
#include "enemy.h"
#include "heal.h"

class Act::Impl{ };

void Act::dbg() { std::cout << "Act system is static" << std::endl; }

template <class T1, class T2>
static void fight(const T1& player, const T2& obj)
{
	dynamic_cast<Player>(T1).decHealthBy(T2.getStrength());
	dynamic_cast<Enemy>(T2).decHealthBy(T1.getStrength());
}

template <class T1, class T2>
void Act::act(const T1& player, const T2& obj) 
{ 
	if (typeid(T1).name() != typeid(Player).name())
		return 0;

	if (typeid(T2).name() == typeid(Enemy).name())
	{
		Act::fight(T1, T2);
	}
	if (typeid(T2).name() == typeid(HealEnt).name())
	{

	}

	//std::cout << typeid(obj).name();

}