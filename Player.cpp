#include "Player.h"
#include<iostream>


Player::Player(const char* backgroundBitmap, const int frames, const int levels)
	: Node(backgroundBitmap), frames(frames), levels(levels)
{

}

Player::~Player()
{
	std::cout << "DESTRUKTOR Z PLAYER" << std::endl;
}

void Player::show()
{
	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->bitmapWidth / frames, this->bitmapHeight / levels, this->xPosition, this->yPosition, 0);
}

void Player::move(ALLEGRO_EVENT events, float backgroundXPosition, int backgroundWidth, int backgroundHeight)
{
	ALLEGRO_KEYBOARD_STATE keyState;
	al_get_keyboard_state(&keyState);

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


	//Boundary lines
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