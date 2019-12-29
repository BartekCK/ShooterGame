#include "Hero.h"
#include <iostream>

Hero::Hero(const char* backgroundBitmap, const int frames, const int levels):Node(backgroundBitmap),frames(frames),levels(levels)
{
	gun = new Gun();

}

Hero::Hero(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels)
	:Node(backgroundBitmap, xPosition, yPosition), frames(frames), levels(levels)
{
	gun = new Gun();
}

Hero::~Hero()
{
	delete gun;
	std::cout << "Dekonstruktor z HERO" << std::endl;
}

bool Hero::checkHit(std::vector<Hero*> heroes)
{

	for (auto hh = heroes.begin(); hh != heroes.end(); hh++) {

		std::vector<Ammo*> ammo = (*hh)->getGun()->getAmmo();

		for (auto it = ammo.begin(); it != ammo.end(); it++) {

			if (((*it)->getEndXPosition() > xPosition && (*it)->getEndXPosition() < xPosition + bitmapWidth / frames )&&
				((*it)->getEndYPosition() > yPosition && (*it)->getEndYPosition() < yPosition + bitmapHeight / levels)) {


				if((*it)->getDirection() == SHOOT_DIRECTION::RIGHT_SHOOT)//Trick 
					(*it)->setXposition(-200000);
				else
				{
					(*it)->setXposition(200000);
				}
				//Action to do when the target was hit

				this -> hp -= 10;

				


				std::cout << "TRAFIONY ZATOPIONY" << std::endl;
				return true;
			}


		}
	}
	return false;
}

bool Hero::checkHp()
{
	if (this->hp <= 0)
		return true;
	else
		return false;
}

int Hero::getHp()
{
	return this->hp;
}

Gun* Hero::getGun()
{
	return this->gun;
}
