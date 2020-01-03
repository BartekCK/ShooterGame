#include "Enemy.h"
#include <iostream>


Enemy::Enemy(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, int hp, Hero* player) 
	: Hero(backgroundBitmap, xPosition, yPosition, frames, levels), 
	player(player)
{
	this->hp = hp;
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
	if (events.timer.source == engine->timmerVector[3]) {
		int safeSpace = 70;
		if (this->shiftY == 0) {//Shot on right
			this->gun->shot(this->xPosition + (this->bitmapWidth / frames) + safeSpace, this->yPosition + (this->bitmapHeight / 4), SHOOT_DIRECTION::RIGHT_SHOOT);
		}
		else //Shot on left
		{
			this->gun->shot(this->xPosition - safeSpace, this->yPosition + (this->bitmapHeight / 4), SHOOT_DIRECTION::LEFT_SHOOT);
		}
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

void Enemy::animation(ALLEGRO_EVENT events)
{
	if (events.timer.source == engine->timmerVector[0]) {
		this->shiftX += ((this->getBitmapWidth() / this->frames));
		if (this->shiftX >= this->getBitmapWidth())
			this->shiftX = 0;
	}
}

