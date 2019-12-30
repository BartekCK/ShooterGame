#include "Player.h"
#include<iostream>
#include "Path.h"
#include <windows.h>


Player::Player(const char* backgroundBitmap, int xPosition, int yPosition, const int frames, const int levels, CONTROL_SOURCE controlSource)
	: Hero(backgroundBitmap, xPosition, yPosition, frames, levels),controlSource(controlSource)
{
	Path path;
	int x = 10;
	if (xPosition >= 100)
		x = GetSystemMetrics(SM_CXSCREEN)-365;
	healthBar = new HealthBar(path.OBJECT_HEALTH_BAR,x,10,10);
}

Player::~Player()
{
	delete healthBar;
	std::cout << "DESTRUKTOR Z PLAYER" << std::endl;
}

void Player::show()
{
	this->healthBar->readHp(this);
	this->healthBar->show();
	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->bitmapWidth / frames, this->bitmapHeight / levels, this->xPosition, this->yPosition, 0);
	this->gun->showBullet();
}

void Player::move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight)
{
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

	if (controlSource == CONTROL_SOURCE::ARROW_CONTROL) {
		if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
			this->yPosition += this->moveSpeed;
			animation(events);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
			this->yPosition -= this->moveSpeed;
			animation(events);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
			this->xPosition -= this->moveSpeed;
			this->shiftY = this->getBitmapHeight() / 2;
			animation(events);

		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
			this->xPosition += this->moveSpeed;
			this->shiftY = 0;
			animation(events);

		}
	}
	else {
		if (al_key_down(&keyState, ALLEGRO_KEY_S)) {
			this->yPosition += this->moveSpeed;
			animation(events);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_W)) {
			this->yPosition -= this->moveSpeed;
			animation(events);
		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_A)) {
			this->xPosition -= this->moveSpeed;
			this->shiftY = this->getBitmapHeight() / 2;
			animation(events);

		}
		else if (al_key_down(&keyState, ALLEGRO_KEY_D)) {
			this->xPosition += this->moveSpeed;
			this->shiftY = 0;
			animation(events);

		}
	}

	useBorders(backgroundXPosition, backgroundWidth, backgroundHeight);
}

void Player::makeShot(ALLEGRO_EVENT events)
{
	if (controlSource == CONTROL_SOURCE::ARROW_CONTROL) {
		if (events.keyboard.keycode == ALLEGRO_KEY_SPACE) {
			chooseShootDirection();
		}
	}
	else {
		if (events.keyboard.keycode == ALLEGRO_KEY_F) {
			chooseShootDirection();
		}
	}
}

void Player::addHealth()
{
	if(this->hp<=90)
		this->hp += 10;
}

HealthBar* Player::getHealthBar()
{
	return this->healthBar;
}



void Player::useBorders(float backgroundXPosition, int backgroundWidth, int backgroundHeight)
{
	if (backgroundXPosition == 0 && this->getXposition() <= backgroundXPosition) {
		this->setXposition(backgroundXPosition);
	}
	if (this->getXposition() <= backgroundXPosition - (backgroundWidth / 2)) {
		this->setXposition(backgroundXPosition - (backgroundWidth / 2));
	}

	if (this->getYposition() <= 0)
		this->setYposition(0);
	if (this->getYposition() >= backgroundHeight - (this->getBitmapHeight() / 2))
		this->setYposition(backgroundHeight - (this->getBitmapHeight() / 2));

}

void Player::animation(ALLEGRO_EVENT events)
{
	if (events.timer.source == engine->timmerVector[0]) {
		this->shiftX += ((this->getBitmapWidth() / this->frames));
		if (this->shiftX >= this->getBitmapWidth())
			this->shiftX = 0;
	}
}

void Player::chooseShootDirection()
{
	int safeSpace = 100;
	if (this->shiftY == 0) {//Shot on right
		this->gun->shot(this->xPosition + (this->bitmapWidth / frames) + safeSpace, this->yPosition + (this->bitmapHeight / 4), SHOOT_DIRECTION::RIGHT_SHOOT);
	}
	else //Shot on left
	{
		this->gun->shot(this->xPosition - safeSpace, this->yPosition + (this->bitmapHeight / 4), SHOOT_DIRECTION::LEFT_SHOOT);
	}
}
