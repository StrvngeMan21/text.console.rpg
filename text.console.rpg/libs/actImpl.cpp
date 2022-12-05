#include "stdafx.h"

#include "act.h"
#include "player.h"
#include "plain.h"
#include "enemy.h"

class Act::Impl{ };

void Act::dbg() { std::cout << "Act system is static" << std::endl; }

template <class T1, class T2>
void Act::act(T1* player, T2* obj) 
{ 
	if (typeid(T1).name() != typeid(Player).name())
		return 0;

	if (typeid(T2).name() == typeid(Enemy).name())
	{
		Player tempP = player;
		Enemy tempE = obj;

		tempE.decHealthBy(tempP.getStrength());
		tempP.decHealthBy(tempE.getStrength());
	}
}