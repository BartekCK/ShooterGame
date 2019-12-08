#pragma once
#include "Ammo.h"
#include<vector>

class Gun
{
	std::vector<Ammo> ammo;
	void allocateMemory();

public:
	Gun();
	~Gun();
	void shot(int x, int y, SHOOT_DIRECTION direction);
	void showBullet();
};

