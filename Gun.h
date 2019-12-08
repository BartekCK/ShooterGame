#pragma once
#include "Ammo.h"

#include<vector>

class Gun
{
	std::vector<Ammo> ammo;

public:
	Gun();
	~Gun();
	void shot(int x, int y, SHOOT_DIRECTION direction);
	void showBullet();
	void allocateMemory();
	std::vector<Ammo> getAmmo();
};

