#include "libs/stdafx.h"
#include "libs/creature.h"

int main()
{
	Creature cr;
	cr.printDbg();
	std::cout << "\n" << cr.getId() << " " << cr.getHealth() << "\n";
}
