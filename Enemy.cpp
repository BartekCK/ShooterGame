#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, HP_VALUE hpValue, MOVE_SPEED moveSpeed, SHOOT_TIME shootTime, Hero* player)
	: Hero(backgroundBitmap, xPosition, yPosition, frames, levels),
	shootTime(shootTime),
	player(player)
{
	this->moveSpeed = (int)moveSpeed;
	this->hp = (int)hpValue;
}


Enemy::~Enemy()
{
	std::cout << "DEKONSTRUKTOR Z ENEMY" << std::endl;
}

void Enemy::show()
{
	
	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->bitmapWidth / frames, this->bitmapHeight / levels, this->xPosition, this->yPosition, 0);
	this->gun->showBullet();

}

void Enemy::makeShot(ALLEGRO_EVENT events)
{
	if (events.timer.source == engine->timmerVector[(int)shootTime]) {

		Hero::makeShot(events);
	}
}

void Enemy::move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight)
{

	if (events.timer.source == engine->timmerVector[0]) {

		//X CORDINATE
		if (player->getXposition() + player->getBitmapWidth() / player->frames < this->xPosition) {
			this->xPosition -= this->moveSpeed;
			this->shiftY = this->getBitmapHeight() / 2;
		}
		else if (player->getXposition() - player->getBitmapWidth() / player->frames > this->xPosition)
		{
			this->xPosition += this->moveSpeed;
			this->shiftY = 0;
		}


		//Y CORDINATE
		if (player->getYposition() > this->yPosition)
			this->yPosition += this->moveSpeed;
		else if (player->getYposition() < this->yPosition)
		{
			this->yPosition -= this->moveSpeed;
		}

		
	}
	//Animation time
	if (!((player->getXposition() + player->getBitmapWidth() / player->frames == this->xPosition ||
		player->getXposition() - player->getBitmapWidth() / player->frames == this->xPosition) &&
		player->getYposition() == this->yPosition)) {
		animation(events);
	}
}

