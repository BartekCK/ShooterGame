#pragma once
#include "Enemy.h"
#include "Player.h"
#include <Windows.h>
class BuildEnemy
{

	static int screen_width;
	static int screen_height;

	static Enemy* getSmallSoldier(Player* player);
	static Enemy* getSoldier(Player* player);
	static Enemy* getGalacticSoldier(Player* player);
	static Enemy* getZombie(Player* player);
	static Enemy* getFastZombie(Player* player);

	static int getRandX(Player* player);
	static int getRandY();
public:

	static Enemy* getBoss(Player* player);
	static Enemy* getEnemy(Player* player);
};

