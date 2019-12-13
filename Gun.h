#pragma once
#include "Ammo.h"

#include<vector>

class Gun
{
	std::vector<Ammo*> ammo;

public:
	Gun();
	~Gun();
	void shot(int x, int y, SHOOT_DIRECTION direction);
	void showBullet();
	bool allocateMemory(vector<Ammo*>::iterator iter);

	std::vector<Ammo*> getAmmo();
};

