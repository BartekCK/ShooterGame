#include "Hero.h"
#include <iostream>

Hero::Hero(const char* backgroundBitmap, const int frames, const int levels):Node(backgroundBitmap),frames(frames),levels(levels)
{
	gun = new Gun();

}

Hero::~Hero()
{
	delete gun;
	std::cout << "Dekonstruktor z Hero" << std::endl;
}

bool Hero::checkHit(std::vector<Hero*> heroes)
{

	

	for (auto hh = heroes.begin(); hh != heroes.end(); hh++) {

		std::vector<Ammo> ammo = (*hh)->getGun()->getAmmo();

		for (auto it = ammo.begin(); it != ammo.end(); it++) {

			if ((*it).getEndXPosition() > xPosition && (*it).getEndXPosition() < xPosition + bitmapWidth / frames &&
				(*it).getEndYPosition() > yPosition && (*it).getEndYPosition() > yPosition < yPosition + bitmapHeight / levels) {
				ammo.erase(it);
				std::cout << "TRAFIONY ZATOPIONY" << std::endl;
				return true;
			}


		}
	}
	return false;
}

Gun* Hero::getGun()
{
	return this->gun;
}
