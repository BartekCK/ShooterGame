#include "Gun.h"
#include <iostream>

Gun::Gun()
{
}

Gun::~Gun()
{
	std::cout << "Desktuktor z GUN" << std::endl;

	for (size_t i = 0; i < ammo.size(); i++) {
		delete ammo[i];
	}
	ammo.clear();
	ammo.shrink_to_fit();
}

void Gun::shot(int x, int y, SHOOT_DIRECTION direction)
{
	ammo.push_back(new Ammo(x, y,direction));
}

void Gun::showBullet()
{
	if (!ammo.empty()) {
		vector<Ammo*>::iterator it;
		for (it = ammo.begin(); it != ammo.end(); it++) {
			
			(*it)->show();
			if (allocateMemory(it)) {
				break;
			}
				
			
		}
		
		
	}

}

bool Gun::allocateMemory(vector<Ammo*>::iterator it)
{

	if ((*it)->getDirection() == SHOOT_DIRECTION::RIGHT_SHOOT) {
		if (((*it)->getEndXPosition() - 1000) > ((*it)->getXposition())) {
			

			if (*it != NULL) {
				Ammo* temp = *it;
				ammo.erase(it);
				delete temp;
				temp = NULL;
			}
			return true;
		}
	}
	else {
		if (((*it)->getEndXPosition() + 1000) < ((*it)->getXposition())) {
			

			if (*it != NULL) {
				Ammo* temp = *it;
				ammo.erase(it);
				delete temp;
				temp = NULL;
			}

			return true;
		}
	}

	return false;

}


std::vector<Ammo*> Gun::getAmmo()
{
	return this->ammo;
}
