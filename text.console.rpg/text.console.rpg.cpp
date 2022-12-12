#include "libs/stdafx.h"
#include "libs/creature.h"
#include "libs/enemy.h"
#include "libs/player.h"
#include "libs/act.h"
#include "libs/map.h"
#include "libs/controls.h"


int main()
{
	Map map;
	map.generate();
	map.refresh();

	ControlSystem::takeControl();

	map.dbg();


}
