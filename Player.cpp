#include "Player.h"



Player::Player(const char* backgroundBitmap, const int frames, const int levels)
	: Node(backgroundBitmap), frames(frames), levels(levels)
{

}

Player::~Player()
{
}

void Player::show()
{
	al_draw_bitmap_region(this->objectBitmap, this->shiftX, this->shiftY, this->bitmapWidth / frames, this->bitmapHeight / levels, this->xPosition, this->yPosition, 0);
}

void Player::move()
{
	ALLEGRO_KEYBOARD_STATE keyState;

	al_get_keyboard_state(&keyState);

	if (al_key_down(&keyState, ALLEGRO_KEY_DOWN)) {
		this->yPosition += this->moveSpeed;
		animation();
	}
	else if (al_key_down(&keyState, ALLEGRO_KEY_UP)) {
		this->yPosition -= this->moveSpeed;
		animation();
	}
	else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT)) {
		this->xPosition -= this->moveSpeed;
		this->shiftY = this->getBitmapHeight() / 2;
		animation();

	}
	else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT)) {
		this->xPosition += this->moveSpeed;
		this->shiftY = 0;
		animation();

	}

	

}



void Player::animation()
{
	this->shiftX += ((this->getBitmapWidth() / this->frames));
	if (this->shiftX >= this->getBitmapWidth())
		this->shiftX = 0;

}