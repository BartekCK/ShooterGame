#include "Gun.h"
#include <iostream>

Gun::Gun()
{
}

Gun::~Gun()
{
	
	std::cout << "Desktuktor z GUN" << std::endl;
}

void Gun::shot(int x, int y, SHOOT_DIRECTION direction)
{
	ammo.push_back(Ammo(x, y,direction));
}

void Gun::showBullet()
{
	if (!ammo.empty()) {
		for (size_t i = 0; i < ammo.size(); i++) {
			ammo[i].show();
		}
		allocateMemory();
	}


	
}

void Gun::allocateMemory()
{
	
	for (auto it = ammo.begin(); it != ammo.end(); it++) {

		if ((*it).getDirection() == SHOOT_DIRECTION::RIGHT_SHOOT) {
			if (((*it).getEndXPosition() - 1000) > ((*it).getXposition())) {
				ammo.erase(it);
				break;
			}
		}
		else {
			if (((*it).getEndXPosition() + 1000) < ((*it).getXposition())) {
				ammo.erase(it);
				break;
			}
		}
		
	}
}