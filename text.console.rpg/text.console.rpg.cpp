#include "libs/stdafx.h"
#include "libs/creature.h"
#include "libs/enemy.h"
#include "libs/player.h"
#include "libs/mapChunk.h"

int main()
{

	Player cr;
	Creature creat;
	int a = 5;
	MapChunk<int> mch_C(a);
	//mch_C.setObj(creat);
	Player& ptr_cr = cr;

	cr.printDbg();
	std::cout << "\n" << cr.getId() << " " << cr.getHealth() << "\n" << &ptr_cr;
	//std::cout << "\n" << mch_C.getObj().getId();
}
