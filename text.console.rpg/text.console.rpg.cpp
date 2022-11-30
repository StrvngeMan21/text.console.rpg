#include "libs/stdafx.h"
#include "libs/creature.h"
#include "libs/enemy.h"
#include "libs/player.h"

int main()
{
	Player cr;
	cr.printDbg();
	std::cout << "\n" << cr.getId() << " " << cr.getHealth() << "\n";
}
