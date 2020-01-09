#include "Hero.h"
#include "Zombie.h"
#include <iostream>

void Hero::animation(ALLEGRO_EVENT events)
{
	if (events.timer.source == engine->timmerVector[0]) {
		this->shiftX += ((this->getBitmapWidth() / this->frames));
		if (this->shiftX >= this->getBitmapWidth())
			this->shiftX = 0;
	}
}


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

void Hero::makeShot(ALLEGRO_EVENT events)
{
	int safeSpace = 70;
	if (this->shiftY == 0) {//Shot on right
		this->gun->shot(this->xPosition + (this->bitmapWidth / frames) + safeSpace, this->yPosition + (this->bitmapHeight / 4), SHOOT_DIRECTION::RIGHT_SHOOT);
	}
	else //Shot on left
	{
		this->gun->shot(this->xPosition - safeSpace, this->yPosition + (this->bitmapHeight / 4), SHOOT_DIRECTION::LEFT_SHOOT);
	}
}

bool Hero::checkHit(std::vector<Hero*> enemies)
{

	

	for (auto hh = enemies.begin(); hh != enemies.end(); hh++) {

		if (Zombie* t = dynamic_cast<Zombie*>(*hh)) {
			if ((*hh)->getXposition() + ((*hh)->getBitmapWidth() / (*hh)->frames) >= xPosition &&
				(*hh)->getXposition() <= xPosition + (bitmapWidth/frames) &&
				(*hh)->getYposition() + ((*hh)->getBitmapHeight() / (*hh)->levels) >= yPosition &&
				(*hh)->getYposition() <= yPosition + (bitmapHeight/levels)
				) {
				//Action when players have collision with ZOMBIE
				this->hp -= 200;
				return true;
			}
		}
		else {
			std::vector<Ammo*> ammo = (*hh)->getGun()->getAmmo();

			for (auto it = ammo.begin(); it != ammo.end(); it++) {

				if (((*it)->getEndXPosition() > xPosition && (*it)->getEndXPosition() < xPosition + bitmapWidth / frames) &&
					((*it)->getEndYPosition() > yPosition && (*it)->getEndYPosition() < yPosition + bitmapHeight / levels)) {


					if ((*it)->getDirection() == SHOOT_DIRECTION::RIGHT_SHOOT)//Trick 
						(*it)->setXposition(-200000);
					else
					{
						(*it)->setXposition(200000);
					}
					//Action to do when the target was hit

					this->hp -= 10;


					return true;
				}


			}
		}



		
	}
	return false;
}

bool Hero::checkHit(Hero* player)
{
	

	std::vector<Ammo*> ammo = player->getGun()->getAmmo();

	for (auto it = ammo.begin(); it != ammo.end(); it++) {

		if (((*it)->getEndXPosition() > xPosition && (*it)->getEndXPosition() < xPosition + bitmapWidth / frames) &&
			((*it)->getEndYPosition() > yPosition && (*it)->getEndYPosition() < yPosition + bitmapHeight / levels)) {


			if ((*it)->getDirection() == SHOOT_DIRECTION::RIGHT_SHOOT)//Trick 
				(*it)->setXposition(-200000);
			else
			{
				(*it)->setXposition(200000);
			}
			//Action to do when the target was hit

			this->hp -= 10;
;
			return true;
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


